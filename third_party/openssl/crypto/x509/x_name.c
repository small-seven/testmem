#include <stdio.h>
#include "crypto/ctype.h"
#include "internal/cryptlib.h"
#include <openssl/asn1t.h>
#include <openssl/x509.h>
#include "crypto/x509.h"
#include "crypto/asn1.h"
#include "x509_local.h"
#define X509_NAME_MAX (1024 * 1024)
static void x509_name_ex_free(ASN1_VALUE **pval, const ASN1_ITEM *it)
{
    X509_NAME *a;

    if (!pval || !*pval)
        return;
    a = (X509_NAME *)*pval;

    BUF_MEM_free(a->bytes);
    sk_X509_NAME_ENTRY_pop_free(a->entries, X509_NAME_ENTRY_free);
    OPENSSL_free(a->canon_enc);
    OPENSSL_free(a);
    *pval = NULL;
}
static void local_sk_X509_NAME_ENTRY_free(STACK_OF(X509_NAME_ENTRY) *ne)
{
    sk_X509_NAME_ENTRY_free(ne);
}
static void local_sk_X509_NAME_ENTRY_pop_free(STACK_OF(X509_NAME_ENTRY) *ne)
{
    sk_X509_NAME_ENTRY_pop_free(ne, X509_NAME_ENTRY_free);
}
#define ASN1_MASK_CANON \
