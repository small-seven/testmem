#include <stdlib.h>
#include <string.h>
#include <openssl/crypto.h>
#include "crypto/siphash.h"
#include "siphash_local.h"
#define SIPHASH_C_ROUNDS 2
#define SIPHASH_D_ROUNDS 4
#define ROTL(x, b) (uint64_t)(((x) << (b)) | ((x) >> (64 - (b))))
#define U32TO8_LE(p, v)                                                        \
#define U64TO8_LE(p, v)                                                        \
#define U8TO64_LE(p)                                                           \
#define SIPROUND                                                               \
