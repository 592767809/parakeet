#pragma once
#include <cstdint>

// Map encryption.
typedef struct qmcv2_map qmcv2_map;
qmcv2_map* qmcv2_map_init(const uint8_t* key, const size_t key_size);
uint8_t qmcv2_map_encrypt(qmcv2_map* ctx, size_t offset);
uint8_t qmcv2_map_decrypt(qmcv2_map* ctx, size_t offset);
void qmcv2_map_free(qmcv2_map*& ctx);

// RC4 encryption.
typedef struct qmcv2_rc4 qmcv2_rc4;
qmcv2_rc4* qmcv2_rc4_init(const uint8_t* key, const size_t key_size);
void qmcv2_rc4_encrypt(qmcv2_rc4* ctx, uint8_t* buf, size_t len, size_t offset);
void qmcv2_rc4_decrypt(qmcv2_rc4* ctx, uint8_t* buf, size_t len, size_t offset);
void qmcv2_rc4_free(qmcv2_rc4*& ctx);

// Key derive

void umc_qmcv2_free_derived_key(uint8_t*& key);
bool umc_qmcv2_derive_from_ekey(uint8_t*& derived_key,
                                size_t& derived_key_len,
                                const uint8_t* ekey,
                                size_t ekey_len);
bool umc_qmcv2_derive_from_ekey_b64(uint8_t*& derived_key,
                                    size_t& derived_key_len,
                                    const char* ekey_b64);
