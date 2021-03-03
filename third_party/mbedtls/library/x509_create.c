#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_X509_CREATE_C)
#include "mbedtls/x509.h"
#include "mbedtls/asn1write.h"
#include "mbedtls/oid.h"
#include <string.h>
typedef struct {
   const char *name; /* String representation of AttributeType, e.g.
                      * "CN" or "emailAddress". */
   size_t name_len;  /* Length of 'name', without trailing 0 byte. */
   const char *oid;  /* String representation of OID of AttributeType,
                      * as per RFC 5280, Appendix A.1. */
   int default_tag;  /* The default character encoding used for the
                      * given attribute type, e.g.
                      * MBEDTLS_ASN1_UTF8_STRING for UTF-8. */
} x509_attr_descriptor_t;
#define ADD_STRLEN( s )     s, sizeof( s ) - 1
#endif /* MBEDTLS_X509_CREATE_C */
