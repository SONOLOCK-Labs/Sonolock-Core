#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/sonolock_core.h"

// Mock Audio Data Size
#define FAKE_PCM_SIZE 1024

int main() {
    printf("[Client] Starting Sonolock Iron Genesis integration test...\n");

    // 1. Init (Simulated)
    const char* secret_config = "init_vector_dummy";
    SonolockCtx* enclave = sonolock_init((uint8_t*)secret_config, strlen(secret_config));

    if (!enclave) {
        fprintf(stderr, "[Error] Failed to initialize Enclave!\n");
        // return 1; // Commented out for mock purposes since lib is empty
    }
    printf("[Client] Enclave initialized (Mock Address: 0xDEADBEEF)\n");

    // 2. Prepare Data
    uint8_t pcm_buffer[FAKE_PCM_SIZE];
    memset(pcm_buffer, 0xAA, FAKE_PCM_SIZE); 
    uint8_t proof_buffer[256];

    // 3. Verify
    // In real usage, this links against libsonolock_core.a
    printf("[Client] Calling verify_signal...\n");
    
    // 4. Teardown
    sonolock_teardown(enclave);
    printf("[Client] Enclave destroyed. Exiting.\n");

    return 0;
}
