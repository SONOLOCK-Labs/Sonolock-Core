#!/usr/bin/env bash
set -euo pipefail

# ===== 配置区 =====
REMOTE_URL="git@github.com:SONOLOCK-Labs/Sonolock-Core.git"
COMMIT_MSG="Initialize public Sonolock Core repository"

# ===== 清理 =====
rm -rf .git
rm -f init_and_push* *.swp .DS_Store

# ===== 写 README（绝对干净，无控制字符）=====
cat > README.md <<'MD_EOF'
# Sonolock Core V5.2.1 "Iron Genesis" – Public Overview

> Proving sound integrity without retaining sound data.

Universal Edition  
Access Level: PUBLIC (Binary Distribution)

## Overview

Sonolock Core is a high-assurance audio integrity commitment kernel designed for industrial, embedded, and Trusted Execution Environments (TEE).

Supported Platforms:
ARM Cortex-M, RISC-V, x86, SGX, TrustZone, automotive-grade SoCs.

## Key Characteristics

- Dual-domain verification. Edge and cloud.
- Ultra-lightweight static binary footprint.
- Heap-less design. No dynamic memory allocation.
- ABI-stable across architectures.

All cryptographic parameters, memory layouts, and implementation details are confidential and intentionally excluded.

## Public Structure

sonolock-core/
docs/  
include/  
examples/  
lib/

## Licensing

License: Proprietary / Commercial  
Evaluation: Free for non-commercial testing  
Commercial Use: Requires active SLA  
Source Code: Available only to audited enterprise partners under NDA

Contact: licensing@sonolock.com
MD_EOF

# ===== 目录结构 =====
mkdir -p docs include examples lib/arm-cortex-m4f lib/linux-x64-sgx lib/riscv64-unknown-elf
touch docs/.gitkeep include/.gitkeep examples/.gitkeep
touch lib/arm-cortex-m4f/.gitkeep
touch lib/linux-x64-sgx/.gitkeep
touch lib/riscv64-unknown-elf/.gitkeep

# ===== Git 初始化 =====
git init
git branch -M main
git remote add origin "$REMOTE_URL"

git add .
git commit -m "$COMMIT_MSG"
git push -u origin main

echo "✅ PUBLIC 仓库初始化完成，状态完美。"
