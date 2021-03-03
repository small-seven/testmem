#include <mbedtls/certs.h>
#include <mbedtls/config.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#include <mbedtls/net_sockets.h>
#include <mbedtls/platform.h>
#include <mbedtls/ssl.h>
#include <mbedtls/x509_crt.h>
#include "avformat.h"
#include "internal.h"
#include "url.h"
#include "tls.h"
#include "libavutil/parseutils.h"
typedef struct TLSContext {
    const AVClass *class;
    TLSShared tls_shared;
    mbedtls_ssl_context ssl_context;
    mbedtls_ssl_config ssl_config;
    mbedtls_entropy_context entropy_context;
    mbedtls_ctr_drbg_context ctr_drbg_context;
    mbedtls_x509_crt ca_cert;
    mbedtls_x509_crt own_cert;
    mbedtls_pk_context priv_key;
    char *priv_key_pw;
} TLSContext;
#define OFFSET(x) offsetof(TLSContext, x)
