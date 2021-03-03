#include "includes.h"
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/pkcs7.h>
#include <openssl/rsa.h>
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/opensslv.h>
#ifdef OPENSSL_IS_BORINGSSL
#include <openssl/buf.h>
#endif /* OPENSSL_IS_BORINGSSL */
#include "common.h"
#include "utils/base64.h"
#include "utils/xml-utils.h"
#include "utils/http-utils.h"
#include "osu_client.h"
#ifdef OPENSSL_IS_BORINGSSL
#else /* OPENSSL_IS_BORINGSSL */
#endif /* OPENSSL_IS_BORINGSSL */
#ifdef OPENSSL_IS_BORINGSSL
#else /* OPENSSL_IS_BORINGSSL */
#endif /* OPENSSL_IS_BORINGSSL */
#ifdef OPENSSL_IS_BORINGSSL
#else /* OPENSSL_IS_BORINGSSL */
#endif /* OPENSSL_IS_BORINGSSL */
typedef struct {
	ASN1_OBJECT *type;
	STACK_OF(ASN1_OBJECT) *values;
} Attribute;
typedef struct {
	int type;
	union {
		ASN1_OBJECT *oid;
		Attribute *attribute;
	} d;
#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(OPENSSL_IS_BORINGSSL)
#endif
typedef struct {
	int type;
	STACK_OF(AttrOrOID) *attrs;
} CsrAttrs;
#ifdef OPENSSL_IS_BORINGSSL
#else /* OPENSSL_IS_BORINGSSL */
#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(OPENSSL_IS_BORINGSSL)
#else
#endif
#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(OPENSSL_IS_BORINGSSL)
#else
#endif
#endif /* OPENSSL_IS_BORINGSSL */
#if !defined(ANDROID) || !defined(OPENSSL_IS_BORINGSSL)
#endif
#if !defined(ANDROID) || !defined(OPENSSL_IS_BORINGSSL)
#endif
