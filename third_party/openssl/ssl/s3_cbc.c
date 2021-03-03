#include "internal/constant_time.h"
#include "ssl_local.h"
#include "internal/cryptlib.h"
#include <openssl/md5.h>
#include <openssl/sha.h>
#define MAX_HASH_BIT_COUNT_BYTES 16
#define MAX_HASH_BLOCK_SIZE 128
#define u32toLE(n, p) \
#undef  LARGEST_DIGEST_CTX
#define LARGEST_DIGEST_CTX SHA512_CTX
