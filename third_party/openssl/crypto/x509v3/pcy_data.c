#include "internal/cryptlib.h"
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include "pcy_local.h"
void policy_data_free(X509_POLICY_DATA *data)
{
    if (data == NULL)
        return;
    ASN1_OBJECT_free(data->valid_policy);
    /* Don't free qualifiers if shared */
    if (!(data->flags & POLICY_DATA_FLAG_SHARED_QUALIFIERS))
        sk_POLICYQUALINFO_pop_free(data->qualifier_set, POLICYQUALINFO_free);
    sk_ASN1_OBJECT_pop_free(data->expected_policy_set, ASN1_OBJECT_free);
    OPENSSL_free(data);
}
