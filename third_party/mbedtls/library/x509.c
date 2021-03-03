#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_X509_USE_C)
#include "mbedtls/x509.h"
#include "mbedtls/asn1.h"
#include "mbedtls/oid.h"
#include <stdio.h>
#include <string.h>
#if defined(MBEDTLS_PEM_PARSE_C)
#include "mbedtls/pem.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#include <stdlib.h>
#define mbedtls_free      free
#define mbedtls_calloc    calloc
#define mbedtls_printf    printf
#define mbedtls_snprintf  snprintf
#endif
#if defined(MBEDTLS_HAVE_TIME)
#include "mbedtls/platform_time.h"
#endif
#if defined(MBEDTLS_HAVE_TIME_DATE)
#include "mbedtls/platform_util.h"
#include <time.h>
#endif
#define CHECK(code) if( ( ret = ( code ) ) != 0 ){ return( ret ); }
#define CHECK_RANGE(min, max, val)                      \
#if defined(MBEDTLS_X509_RSASSA_PSS_SUPPORT)
#endif /* MBEDTLS_X509_RSASSA_PSS_SUPPORT */
#if defined(MBEDTLS_X509_RSASSA_PSS_SUPPORT)
#endif /* MBEDTLS_X509_RSASSA_PSS_SUPPORT */
#if defined(MBEDTLS_X509_RSASSA_PSS_SUPPORT)
#else
#endif /* MBEDTLS_X509_RSASSA_PSS_SUPPORT */
#if defined(MBEDTLS_HAVE_TIME_DATE)
#else  /* MBEDTLS_HAVE_TIME_DATE */
#endif /* MBEDTLS_HAVE_TIME_DATE */
#if defined(MBEDTLS_SELF_TEST)
#include "mbedtls/x509_crt.h"
#include "mbedtls/certs.h"
#if defined(MBEDTLS_CERTS_C) && defined(MBEDTLS_SHA256_C)
#else
#endif /* MBEDTLS_CERTS_C && MBEDTLS_SHA256_C */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_X509_USE_C */
