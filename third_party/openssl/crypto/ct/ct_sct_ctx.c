#ifdef OPENSSL_NO_CT
# error "CT is disabled"
#endif
#include <stddef.h>
#include <string.h>
#include <openssl/err.h>
#include <openssl/obj_mac.h>
#include <openssl/x509.h>
#include "ct_local.h"
void SCT_CTX_free(SCT_CTX *sctx)
{
    if (sctx == NULL)
        return;
    EVP_PKEY_free(sctx->pkey);
    OPENSSL_free(sctx->pkeyhash);
    OPENSSL_free(sctx->ihash);
    OPENSSL_free(sctx->certder);
    OPENSSL_free(sctx->preder);
    OPENSSL_free(sctx);
}
