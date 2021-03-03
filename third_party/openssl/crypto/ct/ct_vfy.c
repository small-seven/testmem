#include <string.h>
#include <openssl/ct.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include "ct_local.h"
typedef enum sct_signature_type_t {
    SIGNATURE_TYPE_NOT_SET = -1,
    SIGNATURE_TYPE_CERT_TIMESTAMP,
    SIGNATURE_TYPE_TREE_HASH
} SCT_SIGNATURE_TYPE;
