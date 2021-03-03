#include <openssl/asn1.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/err.h>
#include "pcy_local.h"
void policy_node_free(X509_POLICY_NODE *node)
{
    OPENSSL_free(node);
}
