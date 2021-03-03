#include <openssl/bn.h>
#include <openssl/err.h>
#include "rsa_local.h"
void rsa_multip_info_free(RSA_PRIME_INFO *pinfo)
{
    /* free a RSA_PRIME_INFO structure */
    BN_clear_free(pinfo->r);
    BN_clear_free(pinfo->d);
    BN_clear_free(pinfo->t);
    rsa_multip_info_free_ex(pinfo);
}
