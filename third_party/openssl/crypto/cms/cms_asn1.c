#include <openssl/asn1t.h>
#include <openssl/pem.h>
#include <openssl/x509v3.h>
#include <openssl/cms.h>
#include "cms_local.h"
typedef struct {
    X509_ALGOR *keyInfo;
    ASN1_OCTET_STRING *entityUInfo;
    ASN1_OCTET_STRING *suppPubInfo;
} CMS_SharedInfo;
