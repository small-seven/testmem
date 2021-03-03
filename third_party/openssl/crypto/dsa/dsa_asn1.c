#include <stdio.h>
#include "internal/cryptlib.h"
#include "dsa_local.h"
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/rand.h>
void DSA_SIG_free(DSA_SIG *sig)
{
    if (sig == NULL)
        return;
    BN_clear_free(sig->r);
    BN_clear_free(sig->s);
    OPENSSL_free(sig);
}
