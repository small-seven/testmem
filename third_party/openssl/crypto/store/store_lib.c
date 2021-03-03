#include "e_os.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "e_os.h"
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/store.h>
#include "internal/thread_once.h"
#include "crypto/store.h"
#include "store_local.h"
void OSSL_STORE_INFO_free(OSSL_STORE_INFO *info)
{
    if (info != NULL) {
        switch (info->type) {
        case OSSL_STORE_INFO_EMBEDDED:
            BUF_MEM_free(info->_.embedded.blob);
            OPENSSL_free(info->_.embedded.pem_name);
            break;
        case OSSL_STORE_INFO_NAME:
            OPENSSL_free(info->_.name.name);
            OPENSSL_free(info->_.name.desc);
            break;
        case OSSL_STORE_INFO_PARAMS:
            EVP_PKEY_free(info->_.params);
            break;
        case OSSL_STORE_INFO_PKEY:
            EVP_PKEY_free(info->_.pkey);
            break;
        case OSSL_STORE_INFO_CERT:
            X509_free(info->_.x509);
            break;
        case OSSL_STORE_INFO_CRL:
            X509_CRL_free(info->_.crl);
            break;
        }
        OPENSSL_free(info);
    }
}
void OSSL_STORE_SEARCH_free(OSSL_STORE_SEARCH *search)
{
    OPENSSL_free(search);
}
