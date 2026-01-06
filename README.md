# SONOLOCK Core SDK (Binary Distribution)

[![Release](https://img.shields.io/badge/release-v5.2.1--iron_genesis-blue)](https://sonolock.io)
[![License](https://img.shields.io/badge/license-Proprietary-red)](./LICENSE)
[![Platform](https://img.shields.io/badge/platform-SGX%20%7C%20TrustZone%20%7C%20RISC--V-lightgrey)]()

**The Industry Standard for Cryptographic Sound Authentication & RWA Transformation.**

> **Notice:** This repository contains the **binary distribution** of the SONOLOCK Core engine. Source code is strictly confidential and available only to Enterprise Partners with a valid SLA.

## 🚀 Overview
SONOLOCK Core is a high-performance, memory-safe security middleware written in Rust, designed to run inside TEE (Trusted Execution Environments). It transforms raw audio signals into verifiable, immutable digital assets (Real World Assets) using hardware-enforced isolation.

## 🛡️ Key Features
- **Iron Genesis Architecture (V5.2.1):** Zero-allocation parsing engine for ultra-low latency.
- **Hardware Agnostic:** Unified API for Intel SGX, ARM TrustZone, and RISC-V PMP.
- **Tamper-Proof:** Core logic executes in encrypted memory enclaves; host OS cannot inspect internal state.
- **C-ABI Compatible:** Seamless integration with C/C++, Python, Go, and Java wrappers.

## 📦 Directory Structure
- `include/`: C-compatible header files (ISO C99 standard).
- `lib/`: Pre-compiled static libraries (`.a`) for supported architectures.
- `docs/`: Integration guides and high-level architectural specs.
- `examples/`: Minimalistic C examples showing how to link and invoke the verifier.

## 🔗 Quick Start
Please refer to [INTEGRATION_GUIDE.md](./docs/INTEGRATION_GUIDE.md) for linking instructions.

---
Copyright (c) 2026 SONOLOCK Inc. All Rights Reserved.
