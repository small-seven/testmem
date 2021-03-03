#include "internal/cryptlib.h"
#include "bn_local.h"
void BN_RECP_CTX_free(BN_RECP_CTX *recp)
{
    if (recp == NULL)
        return;
    BN_free(&recp->N);
    BN_free(&recp->Nr);
    if (recp->flags & BN_FLG_MALLOCED)
        OPENSSL_free(recp);
}
