"""
Tests for the AI Microservices Generator
"""
import json
from pathlib import Path

import pytest

# ---------------------------------------------------------------------------
# Make sure we can import from the ai-module directory
# ---------------------------------------------------------------------------
import sys
sys.path.insert(0, str(Path(__file__).parent.parent))

from generator import ProjectSpec, ServiceSpec, scaffold, _build_readme


# ─────────────────────────────────────────────────────────────────────────────
# Fixtures
# ─────────────────────────────────────────────────────────────────────────────

@pytest.fixture
def simple_spec():
    return ProjectSpec(
        project_name="test-app",
        services=[
            ServiceSpec(name="user",    port=4001),
            ServiceSpec(name="product", port=4002),
        ],
    )


# ─────────────────────────────────────────────────────────────────────────────
# ProjectSpec unit tests
# ─────────────────────────────────────────────────────────────────────────────

class TestProjectSpec:
    def test_first_service_returns_first_name(self, simple_spec):
        assert simple_spec.first_service == "user"

    def test_first_service_empty_returns_default(self):
        spec = ProjectSpec(project_name="empty")
        assert spec.first_service == "resource"

    def test_service_spec_stores_name_and_port(self):
        s = ServiceSpec(name="order", port=4003)
        assert s.name == "order"
        assert s.port == 4003


# ─────────────────────────────────────────────────────────────────────────────
# Scaffold integration tests
# ─────────────────────────────────────────────────────────────────────────────

class TestScaffold:
    def test_scaffold_creates_docker_compose(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        dc = tmp_path / "test-app" / "docker-compose.yml"
        assert dc.exists(), "docker-compose.yml not generated"
        content = dc.read_text()
        assert "user" in content
        assert "product" in content

    def test_scaffold_creates_api_gateway(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        gw_server  = tmp_path / "test-app" / "api-gateway" / "server.js"
        gw_package = tmp_path / "test-app" / "api-gateway" / "package.json"
        gw_docker  = tmp_path / "test-app" / "api-gateway" / "Dockerfile"
        assert gw_server.exists()
        assert gw_package.exists()
        assert gw_docker.exists()

    def test_api_gateway_routes_all_services(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        content = (tmp_path / "test-app" / "api-gateway" / "server.js").read_text()
        assert "/api/users" in content
        assert "/api/products" in content

    def test_scaffold_creates_per_service_files(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        for svc in simple_spec.services:
            base = tmp_path / "test-app" / "services" / svc.name
            assert (base / "server.js").exists(),        f"server.js missing for {svc.name}"
            assert (base / "package.json").exists(),     f"package.json missing for {svc.name}"
            assert (base / "Dockerfile").exists(),       f"Dockerfile missing for {svc.name}"
            assert (base / "init.sql").exists(),         f"init.sql missing for {svc.name}"
            assert (base / "server.test.js").exists(),   f"server.test.js missing for {svc.name}"

    def test_service_server_contains_correct_port(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        content = (tmp_path / "test-app" / "services" / "user" / "server.js").read_text()
        assert "4001" in content

    def test_service_init_sql_creates_table_with_trigger(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        sql = (tmp_path / "test-app" / "services" / "user" / "init.sql").read_text()
        assert "CREATE TABLE" in sql
        assert "users" in sql
        assert "set_updated_at" in sql

    def test_scaffold_creates_frontend_files(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        fe = tmp_path / "test-app" / "frontend"
        assert (fe / "src" / "App.jsx").exists()
        assert (fe / "Dockerfile").exists()
        assert (fe / "nginx.conf").exists()
        assert (fe / "package.json").exists()
        assert (fe / "public" / "index.html").exists()
        assert (fe / "src" / "index.js").exists()

    def test_frontend_package_json_is_valid(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        pkg_path = tmp_path / "test-app" / "frontend" / "package.json"
        pkg = json.loads(pkg_path.read_text())
        assert "react" in pkg["dependencies"]
        assert pkg["name"] == "test-app-frontend"

    def test_scaffold_creates_gitignore(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        gi = tmp_path / "test-app" / ".gitignore"
        assert gi.exists()
        assert "node_modules" in gi.read_text()

    def test_scaffold_creates_readme(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        readme = tmp_path / "test-app" / "README.md"
        assert readme.exists()
        content = readme.read_text()
        # project_name "test-app" becomes "Test App" in the markdown title
        assert "Test App" in content or "test-app" in content

    def test_docker_compose_contains_all_services(self, simple_spec, tmp_path):
        scaffold(simple_spec, tmp_path)
        dc = (tmp_path / "test-app" / "docker-compose.yml").read_text()
        assert "db-user" in dc
        assert "db-product" in dc
        assert "frontend" in dc
        assert "api-gateway" in dc

    def test_single_service_scaffold(self, tmp_path):
        spec = ProjectSpec(
            project_name="solo",
            services=[ServiceSpec(name="order", port=5000)],
        )
        scaffold(spec, tmp_path)
        assert (tmp_path / "solo" / "services" / "order" / "server.js").exists()


# ─────────────────────────────────────────────────────────────────────────────
# README builder tests
# ─────────────────────────────────────────────────────────────────────────────

class TestBuildReadme:
    def test_readme_contains_project_name(self, simple_spec):
        readme = _build_readme(simple_spec)
        # project_name "test-app" becomes "Test App" in the title
        assert "Test App" in readme or "test-app" in readme

    def test_readme_contains_all_service_names(self, simple_spec):
        readme = _build_readme(simple_spec)
        for svc in simple_spec.services:
            assert svc.name in readme

    def test_readme_contains_docker_compose_command(self, simple_spec):
        readme = _build_readme(simple_spec)
        assert "docker compose up" in readme

    def test_readme_includes_description_when_present(self):
        spec = ProjectSpec(
            project_name="ai-app",
            services=[ServiceSpec(name="user", port=4001)],
            description="This is an AI-generated description.",
        )
        readme = _build_readme(spec)
        assert "AI-generated description" in readme
