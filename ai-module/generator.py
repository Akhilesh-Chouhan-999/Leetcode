#!/usr/bin/env python3
"""
AI-powered Fullstack Microservices Generator
=============================================
Generates a production-ready fullstack microservices project with:
  - React frontend
  - Express.js API Gateway
  - N Express/PostgreSQL microservices
  - Docker Compose orchestration

Usage
-----
  # Interactive wizard (recommended)
  python generator.py generate

  # Non-interactive
  python generator.py generate \\
      --project myapp \\
      --services "user:4001,product:4002,order:4003"

  # Use OpenAI to enrich the architecture description
  OPENAI_API_KEY=sk-... python generator.py generate --ai

Environment variables
---------------------
  OPENAI_API_KEY  –  Optional. When set the generator calls GPT-4o to
                     produce a richer project description and service plan.
"""

import os
import sys
import json
import textwrap
from dataclasses import dataclass, field
from pathlib import Path
from typing import List, Optional

import click
from jinja2 import Environment, FileSystemLoader
from rich.console import Console
from rich.panel import Panel
from rich.progress import Progress, SpinnerColumn, TextColumn
from rich.table import Table
from rich.text import Text

console = Console()

TEMPLATES_DIR = Path(__file__).parent / "templates"


# ─────────────────────────────────────────────────────────────────────────────
# Data models
# ─────────────────────────────────────────────────────────────────────────────

@dataclass
class ServiceSpec:
    name: str
    port: int


@dataclass
class ProjectSpec:
    project_name: str
    services: List[ServiceSpec] = field(default_factory=list)
    description: str = ""

    @property
    def first_service(self) -> str:
        return self.services[0].name if self.services else "resource"


# ─────────────────────────────────────────────────────────────────────────────
# OpenAI helper (optional)
# ─────────────────────────────────────────────────────────────────────────────

def _ai_enrich(spec: ProjectSpec) -> str:
    """Ask GPT-4o for an architecture overview. Requires OPENAI_API_KEY."""
    try:
        import openai  # noqa: PLC0415
    except ImportError:
        console.print("[yellow]openai package not installed – skipping AI enrichment.[/yellow]")
        return ""

    api_key = os.environ.get("OPENAI_API_KEY", "")
    if not api_key:
        console.print("[yellow]OPENAI_API_KEY not set – skipping AI enrichment.[/yellow]")
        return ""

    service_list = ", ".join(s.name for s in spec.services)
    prompt = textwrap.dedent(f"""
        You are a senior software architect.
        Generate a concise (≤ 200 words) architecture overview for a fullstack
        microservices project named "{spec.project_name}" that consists of the
        following backend services: {service_list}.
        Include notes on communication patterns, database-per-service pattern,
        and the React frontend interacting through an API Gateway.
        Return plain text only, no markdown.
    """).strip()

    client = openai.OpenAI(api_key=api_key)
    response = client.chat.completions.create(
        model="gpt-4o",
        messages=[{"role": "user", "content": prompt}],
        max_tokens=300,
    )
    return response.choices[0].message.content.strip()


# ─────────────────────────────────────────────────────────────────────────────
# Scaffolding logic
# ─────────────────────────────────────────────────────────────────────────────

def _jinja_env() -> Environment:
    return Environment(
        loader=FileSystemLoader(str(TEMPLATES_DIR)),
        keep_trailing_newline=True,
    )


def _render(env: Environment, template_name: str, **ctx) -> str:
    return env.get_template(template_name).render(**ctx)


def _write(path: Path, content: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content, encoding="utf-8")


def scaffold(spec: ProjectSpec, output_dir: Path) -> List[Path]:
    """Write the full project tree to *output_dir*."""
    env = _jinja_env()
    root = output_dir / spec.project_name

    svc_dicts = [{"name": s.name, "port": s.port} for s in spec.services]
    common = dict(
        project_name=spec.project_name,
        services=svc_dicts,
        first_service=spec.first_service,
    )

    files_written: List[Path] = []

    def w(rel: str, tmpl: str, **extra) -> None:
        content = _render(env, tmpl, **common, **extra)
        dest = root / rel
        _write(dest, content)
        files_written.append(dest)

    # ── docker-compose ──────────────────────────────────────────────────────
    w("docker-compose.yml", "docker-compose.yml.j2")

    # ── API Gateway ─────────────────────────────────────────────────────────
    w("api-gateway/server.js", "gateway_server.js.j2")
    w("api-gateway/package.json", "gateway_package.json.j2")
    w("api-gateway/Dockerfile", "gateway_Dockerfile.j2")

    # ── Per-service ─────────────────────────────────────────────────────────
    for svc in spec.services:
        base = f"services/{svc.name}"
        w(f"{base}/server.js",        "service_server.js.j2",        service_name=svc.name, port=svc.port)
        w(f"{base}/package.json",      "service_package.json.j2",      service_name=svc.name, port=svc.port)
        w(f"{base}/Dockerfile",        "service_Dockerfile.j2",        service_name=svc.name, port=svc.port)
        w(f"{base}/init.sql",          "service_init.sql.j2",          service_name=svc.name, port=svc.port)
        w(f"{base}/server.test.js",    "service_server.test.js.j2",    service_name=svc.name, port=svc.port)

    # ── Frontend ────────────────────────────────────────────────────────────
    w("frontend/src/App.jsx",  "frontend_App.jsx.j2")
    w("frontend/Dockerfile",   "frontend_Dockerfile.j2")
    w("frontend/nginx.conf",   "frontend_nginx.conf.j2")

    # ── Minimal frontend package.json (static, no template needed) ──────────
    pkg = {
        "name": f"{spec.project_name}-frontend",
        "version": "1.0.0",
        "private": True,
        "dependencies": {
            "react": "^18.2.0",
            "react-dom": "^18.2.0",
            "react-scripts": "5.0.1",
        },
        "scripts": {"start": "react-scripts start", "build": "react-scripts build"},
    }
    _write(root / "frontend/package.json", json.dumps(pkg, indent=2) + "\n")

    # ── Minimal frontend index.html ─────────────────────────────────────────
    index_html = textwrap.dedent(f"""\
        <!DOCTYPE html>
        <html lang="en">
          <head>
            <meta charset="UTF-8" />
            <meta name="viewport" content="width=device-width, initial-scale=1.0" />
            <title>{spec.project_name.replace('-', ' ').title()}</title>
          </head>
          <body>
            <div id="root"></div>
          </body>
        </html>
    """)
    _write(root / "frontend/public/index.html", index_html)

    # ── Frontend entry point ────────────────────────────────────────────────
    index_js = textwrap.dedent("""\
        import React from 'react';
        import ReactDOM from 'react-dom/client';
        import App from './App';

        const root = ReactDOM.createRoot(document.getElementById('root'));
        root.render(<React.StrictMode><App /></React.StrictMode>);
    """)
    _write(root / "frontend/src/index.js", index_js)

    # ── .gitignore ──────────────────────────────────────────────────────────
    gitignore = textwrap.dedent("""\
        node_modules/
        .env
        .env.local
        dist/
        build/
        *.log
        .DS_Store
    """)
    _write(root / ".gitignore", gitignore)

    # ── README ──────────────────────────────────────────────────────────────
    readme = _build_readme(spec)
    _write(root / "README.md", readme)

    return files_written


def _build_readme(spec: ProjectSpec) -> str:
    svc_rows = "\n".join(
        f"| `{s.name}` | `http://localhost:{s.port}` | PostgreSQL |"
        for s in spec.services
    )
    desc_section = f"\n{spec.description}\n" if spec.description else ""
    return textwrap.dedent(f"""\
        # {spec.project_name.replace('-', ' ').title()}
        {desc_section}
        Auto-generated fullstack microservices project.

        ## Architecture

        | Layer        | Technology          |
        |--------------|---------------------|
        | Frontend     | React 18            |
        | API Gateway  | Express + http-proxy-middleware |
        | Services     | Express + PostgreSQL |
        | Container    | Docker / Docker Compose |

        ## Services

        | Service | URL | Database |
        |---------|-----|----------|
        | Frontend | `http://localhost:3000` | – |
        | API Gateway | `http://localhost:8080` | – |
        {svc_rows}

        ## Quick Start

        ```bash
        docker compose up --build
        ```

        The frontend will be available at **http://localhost:3000**.

        ## Development

        Each service lives in `services/<name>/`.  
        Run a service locally:

        ```bash
        cd services/<name>
        npm install
        DATABASE_URL=postgresql://... npm run dev
        ```
    """)


# ─────────────────────────────────────────────────────────────────────────────
# CLI
# ─────────────────────────────────────────────────────────────────────────────

@click.group()
def cli():
    """AI-powered Fullstack Microservices Generator."""


@cli.command()
@click.option("--project",  default="", help="Project name (kebab-case)")
@click.option("--services", default="",
              help='Comma-separated list of services, e.g. "user:4001,product:4002"')
@click.option("--output",   default=".", show_default=True,
              help="Directory where the project will be created")
@click.option("--ai",       is_flag=True, default=False,
              help="Use OpenAI to generate an architecture description (needs OPENAI_API_KEY)")
def generate(project: str, services: str, output: str, ai: bool):
    """Scaffold a new fullstack microservices project."""

    console.print(Panel.fit(
        Text("✨ Fullstack Microservices Generator", style="bold cyan"),
        subtitle="AI-powered scaffolding",
    ))

    # ── Gather project name ──────────────────────────────────────────────────
    if not project:
        project = click.prompt(
            "Project name (kebab-case)",
            default="my-app",
        )
    project = project.strip().lower().replace(" ", "-")

    # ── Gather services ──────────────────────────────────────────────────────
    service_specs: List[ServiceSpec] = []

    if services:
        for item in services.split(","):
            item = item.strip()
            if ":" in item:
                name, port_str = item.split(":", 1)
                service_specs.append(ServiceSpec(name=name.strip(), port=int(port_str.strip())))
            else:
                console.print(f"[red]Invalid service spec '{item}'. Use 'name:port'.[/red]")
                sys.exit(1)
    else:
        console.print("\n[bold]Define your microservices[/bold] (leave name blank to finish)\n")
        default_port = 4001
        while True:
            name = click.prompt("  Service name (e.g. user, product, order)", default="").strip()
            if not name:
                if not service_specs:
                    console.print("[yellow]At least one service is required.[/yellow]")
                    continue
                break
            port = click.prompt(f"  Port for '{name}'", default=default_port)
            service_specs.append(ServiceSpec(name=name, port=int(port)))
            default_port += 1

    # ── Build spec ───────────────────────────────────────────────────────────
    spec = ProjectSpec(project_name=project, services=service_specs)

    # ── Optional AI enrichment ───────────────────────────────────────────────
    if ai:
        with Progress(SpinnerColumn(), TextColumn("[progress.description]{task.description}"),
                      transient=True) as progress:
            progress.add_task("Asking GPT-4o for architecture overview…", total=None)
            spec.description = _ai_enrich(spec)
        if spec.description:
            console.print(Panel(spec.description, title="AI Architecture Overview", style="dim"))

    # ── Summary table ────────────────────────────────────────────────────────
    table = Table(title=f"Project: [bold]{project}[/bold]")
    table.add_column("Service", style="cyan")
    table.add_column("Port", justify="right")
    for s in spec.services:
        table.add_row(s.name, str(s.port))
    console.print(table)

    if not click.confirm("\nGenerate project?", default=True):
        console.print("[yellow]Aborted.[/yellow]")
        sys.exit(0)

    # ── Scaffold ─────────────────────────────────────────────────────────────
    output_path = Path(output).resolve()
    with Progress(SpinnerColumn(), TextColumn("[progress.description]{task.description}"),
                  transient=True) as progress:
        progress.add_task("Generating project files…", total=None)
        files = scaffold(spec, output_path)

    console.print(f"\n[bold green]✅ Project generated at {output_path / project}[/bold green]")
    console.print("\n[bold]Next steps:[/bold]")
    console.print(f"  cd {output_path / project}")
    console.print("  docker compose up --build")
    console.print("\nFrontend → http://localhost:3000")
    console.print("API Gateway → http://localhost:8080\n")


@cli.command()
def list_templates():
    """List available template files."""
    table = Table(title="Available Templates")
    table.add_column("File", style="cyan")
    for tmpl in sorted(TEMPLATES_DIR.glob("*.j2")):
        table.add_row(tmpl.name)
    console.print(table)


if __name__ == "__main__":
    cli()
