#include <stdio.h>
#include "internal/cryptlib.h"
#ifndef OPENSSL_NO_DES
# include <openssl/evp.h>
# include <openssl/objects.h>
# include "crypto/evp.h"
# include <openssl/des.h>
# include <openssl/rand.h>
typedef struct {
    union {
        double align;
        DES_key_schedule ks;
    } ks;
# if defined(AES_ASM) && (defined(__sparc) || defined(__sparc__))
#  include "sparc_arch.h"
#  define SPARC_DES_CAPABLE       (OPENSSL_sparcv9cap_P[1] & CFR_DES)
# endif
# if defined(SPARC_DES_CAPABLE)
# endif
#endif
