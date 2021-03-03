#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include "internal/numbers.h"
#ifndef OPENSSL_NO_SCRYPT
#define R(a,b) (((a) << (b)) | ((a) >> (32 - (b))))
#ifndef SIZE_MAX
# define SIZE_MAX    ((size_t)-1)
#endif
#define LOG2_UINT64_MAX         (sizeof(uint64_t) * 8 - 1)
#define SCRYPT_PR_MAX   ((1 << 30) - 1)
#ifdef SCRYPT_MAX_MEM
# if SCRYPT_MAX_MEM == 0
#  undef SCRYPT_MAX_MEM
#  define SCRYPT_MAX_MEM (SIZE_MAX/2)
# endif
#else
# define SCRYPT_MAX_MEM  (1024 * 1024 * 32)
#endif
#endif
