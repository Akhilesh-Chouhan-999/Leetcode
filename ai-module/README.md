# 🤖 AI Fullstack Microservices Generator

An AI-powered command-line tool that scaffolds a **production-ready fullstack microservices project** in seconds.

---

## What It Generates

```
<project-name>/
├── docker-compose.yml          ← orchestrates every container
├── .gitignore
├── README.md                   ← generated docs for your new project
│
├── api-gateway/                ← Express proxy that routes /api/* calls
│   ├── server.js
│   ├── package.json
│   └── Dockerfile
│
├── services/
│   ├── <service-1>/            ← Express + PostgreSQL CRUD service
│   │   ├── server.js
│   │   ├── package.json
│   │   ├── Dockerfile
│   │   └── init.sql
│   └── <service-N>/            ← one folder per service
│
└── frontend/                   ← React 18 SPA
    ├── src/
    │   ├── App.jsx
    │   └── index.js
    ├── public/
    │   └── index.html
    ├── package.json
    ├── nginx.conf
    └── Dockerfile
```

### Tech Stack

| Layer | Technology |
|---|---|
| Frontend | React 18 + nginx |
| API Gateway | Express + http-proxy-middleware |
| Microservices | Node.js / Express |
| Database | PostgreSQL 15 (one DB per service) |
| Containers | Docker / Docker Compose |
| AI enrichment | OpenAI GPT-4o (optional) |

---

## Installation

```bash
cd ai-module
pip install -r requirements.txt
```

---

## Usage

### Interactive wizard (recommended)

```bash
python generator.py generate
```

The wizard asks for the project name and lets you define each microservice interactively.

### Non-interactive (CI / scripting)

```bash
python generator.py generate \
  --project my-shop \
  --services "user:4001,product:4002,order:4003" \
  --output ./projects
```

### With AI architecture description

Set your OpenAI API key and add `--ai`:

```bash
OPENAI_API_KEY=sk-... python generator.py generate \
  --project my-shop \
  --services "user:4001,product:4002" \
  --ai
```

GPT-4o will generate an architecture overview that is included in the project's `README.md`.

### Options

| Flag | Description | Default |
|------|-------------|---------|
| `--project` | Project name (kebab-case) | prompted |
| `--services` | `name:port` pairs, comma-separated | prompted |
| `--output` | Destination directory | `.` |
| `--ai` | Call OpenAI for architecture overview | off |

---

## Running the generated project

```bash
cd <project-name>
docker compose up --build
```

| Service | URL |
|---------|-----|
| Frontend | http://localhost:3000 |
| API Gateway | http://localhost:8080 |
| user service | http://localhost:4001 |
| product service | http://localhost:4002 |

---

## Running the tests

```bash
cd ai-module
pip install -r requirements.txt pytest
python -m pytest tests/ -v
```

---

## Templates

All scaffolding templates live in `templates/` as Jinja2 `.j2` files.

```bash
python generator.py list-templates
```

| Template | Purpose |
|---|---|
| `docker-compose.yml.j2` | Full Compose file |
| `gateway_server.js.j2` | API Gateway code |
| `gateway_package.json.j2` | API Gateway dependencies |
| `gateway_Dockerfile.j2` | API Gateway container |
| `service_server.js.j2` | CRUD microservice code |
| `service_package.json.j2` | Service dependencies |
| `service_Dockerfile.j2` | Service container |
| `service_init.sql.j2` | DB schema |
| `frontend_App.jsx.j2` | React App component |
| `frontend_Dockerfile.j2` | Frontend container (multi-stage) |
| `frontend_nginx.conf.j2` | nginx config |
