#include "eng_local.h"
#include <openssl/evp.h>
void engine_pkey_meths_free(ENGINE *e)
{
    int i;
    EVP_PKEY_METHOD *pkm;
    if (e->pkey_meths) {
        const int *pknids;
        int npknids;
        npknids = e->pkey_meths(e, NULL, &pknids, 0);
        for (i = 0; i < npknids; i++) {
            if (e->pkey_meths(e, &pkm, NULL, pknids[i])) {
                EVP_PKEY_meth_free(pkm);
            }
        }
    }
}
