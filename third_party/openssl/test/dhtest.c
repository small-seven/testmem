#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "internal/nelem.h"
#include <openssl/crypto.h>
#include <openssl/bio.h>
#include <openssl/bn.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/obj_mac.h>
#include "testutil.h"
#ifndef OPENSSL_NO_DH
# include <openssl/dh.h>
typedef struct {
    DH *(*get_param) (void);
    const unsigned char *xA;
    size_t xA_len;
    const unsigned char *yA;
    size_t yA_len;
    const unsigned char *xB;
    size_t xB_len;
    const unsigned char *yB;
    size_t yB_len;
    const unsigned char *Z;
    size_t Z_len;
} rfc5114_td;
# define make_rfc5114_td(pre) { \
#endif
#ifdef OPENSSL_NO_DH
#else
#endif
