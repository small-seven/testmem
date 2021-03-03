#ifdef OPENSSL_NO_CT
# error "CT disabled"
#endif
#include <openssl/ct.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/tls1.h>
#include <openssl/x509.h>
#include "ct_local.h"
void SCT_free(SCT *sct)
{
    if (sct == NULL)
        return;

    OPENSSL_free(sct->log_id);
    OPENSSL_free(sct->ext);
    OPENSSL_free(sct->sig);
    OPENSSL_free(sct->sct);
    OPENSSL_free(sct);
}
void SCT_LIST_free(STACK_OF(SCT) *a)
{
    sk_SCT_pop_free(a, SCT_free);
}
