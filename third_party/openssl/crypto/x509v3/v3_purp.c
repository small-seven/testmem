#include <stdio.h>
#include "internal/cryptlib.h"
#include "internal/numbers.h"
#include <openssl/x509v3.h>
#include <openssl/x509_vfy.h>
#include "crypto/x509.h"
#include "internal/tsan_assist.h"
#define X509_PURPOSE_COUNT OSSL_NELEM(xstandard)
static void xptable_free(X509_PURPOSE *p)
{
    if (!p)
        return;
    if (p->flags & X509_PURPOSE_DYNAMIC) {
        if (p->flags & X509_PURPOSE_DYNAMIC_NAME) {
            OPENSSL_free(p->name);
            OPENSSL_free(p->sname);
        }
        OPENSSL_free(p);
    }
}
#ifndef OPENSSL_NO_RFC3779
#endif
#define V1_ROOT (EXFLAG_V1|EXFLAG_SS)
#define ku_reject(x, usage) \
#define xku_reject(x, usage) \
#define ns_reject(x, usage) \
#ifdef tsan_ld_acq
#endif
#ifndef OPENSSL_NO_RFC3779
#endif
#ifdef tsan_st_rel
#endif
#define KU_TLS \
