/*
 * SONOLOCK CORE API DEFINITION
 * Version: 5.2.1 (Iron Genesis)
 * Copyright (c) 2026 SONOLOCK Inc. All Rights Reserved.
 *
 * CONFIDENTIAL: This header file defines the public interface for the
 * Sonolock Secure Enclave.
 */

#ifndef SONOLOCK_CORE_H
#define SONOLOCK_CORE_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --- Type Definitions --- */

/**
 * @brief Opaque handle to a Sonolock Verifier instance.
 * Internal memory layout is hidden and subject to change.
 */
typedef struct SonolockCtx SonolockCtx;

/**
 * @brief Error codes returned by the enclave.
 */
typedef enum {
    SONOLOCK_SUCCESS = 0,
    SONOLOCK_ERR_INVALID_SIG = -1,
    SONOLOCK_ERR_ENCLAVE_BUSY = -2,
    SONOLOCK_ERR_TAMPER_DETECTED = -99
} sonolock_status_t;

/* --- API Functions --- */

/**
 * @brief Initialize the secure enclave and allocate resources.
 * @param config_ptr  Pointer to configuration buffer (encrypted).
 * @param config_len  Length of the configuration buffer.
 * @return SonolockCtx* Handle to the new instance, or NULL on failure.
 */
SonolockCtx* sonolock_init(const uint8_t* config_ptr, size_t config_len);

/**
 * @brief The core verification function. Takes a raw audio frame and produces
 * a cryptographic proof.
 * @param ctx         Valid Sonolock instance handle.
 * @param pcm_data    Raw PCM audio data pointer.
 * @param data_len    Length of PCM data.
 * @param out_proof   Buffer to store the generated ZK-Proof.
 * @param proof_cap   Capacity of the proof buffer.
 * @return sonolock_status_t Status code.
 */
sonolock_status_t sonolock_verify_signal(
    SonolockCtx* ctx,
    const uint8_t* pcm_data,
    size_t data_len,
    uint8_t* out_proof,
    size_t proof_cap
);

/**
 * @brief Securely tears down the enclave and wipes memory.
 * @param ctx  Handle to the instance to destroy.
 */
void sonolock_teardown(SonolockCtx* ctx);

#ifdef __cplusplus
}
#endif

#endif // SONOLOCK_CORE_H
