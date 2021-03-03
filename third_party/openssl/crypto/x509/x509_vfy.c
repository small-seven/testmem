#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <limits.h>
#include "crypto/ctype.h"
#include "internal/cryptlib.h"
#include <openssl/crypto.h>
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include <openssl/asn1.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/objects.h>
#include "internal/dane.h"
#include "crypto/x509.h"
#include "x509_local.h"
#define CRL_SCORE_NOCRITICAL    0x100
#define CRL_SCORE_SCOPE         0x080
#define CRL_SCORE_TIME          0x040
#define CRL_SCORE_ISSUER_NAME   0x020
#define CRL_SCORE_VALID (CRL_SCORE_NOCRITICAL|CRL_SCORE_TIME|CRL_SCORE_SCOPE)
#define CRL_SCORE_ISSUER_CERT   0x018
#define CRL_SCORE_SAME_PATH     0x008
#define CRL_SCORE_AKID          0x004
#define CRL_SCORE_TIME_DELTA    0x002
#ifndef OPENSSL_NO_RFC3779
#endif
#ifdef CHARSET_EBCDIC
#else
#endif
void X509_STORE_CTX_free(X509_STORE_CTX *ctx)
{
    if (ctx == NULL)
        return;

    X509_STORE_CTX_cleanup(ctx);
    OPENSSL_free(ctx);
}
#define DANETLS_NONE 256        /* impossible uint8_t */
#define S_DOUNTRUSTED      (1 << 0)     /* Search untrusted chain */
#define S_DOTRUSTED        (1 << 1)     /* Search trusted store */
#define S_DOALTERNATE      (1 << 2)     /* Retry with pruned alternate chain */
