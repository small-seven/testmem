#include "e_os.h"
#include "eng_local.h"
#include <openssl/evp.h>
#include "crypto/asn1.h"
void engine_pkey_asn1_meths_free(ENGINE *e)
{
    int i;
    EVP_PKEY_ASN1_METHOD *pkm;
    if (e->pkey_asn1_meths) {
        const int *pknids;
        int npknids;
        npknids = e->pkey_asn1_meths(e, NULL, &pknids, 0);
        for (i = 0; i < npknids; i++) {
            if (e->pkey_asn1_meths(e, &pkm, NULL, pknids[i])) {
                EVP_PKEY_asn1_free(pkm);
            }
        }
    }
}
typedef struct {
    ENGINE *e;
    const EVP_PKEY_ASN1_METHOD *ameth;
    const char *str;
    int len;
} ENGINE_FIND_STR;
