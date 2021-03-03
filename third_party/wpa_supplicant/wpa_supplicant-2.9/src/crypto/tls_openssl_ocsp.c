#include "includes.h"
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/x509v3.h>
#ifdef OPENSSL_IS_BORINGSSL
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#endif /* OPENSSL_IS_BORINGSSL */
#include "common.h"
#include "tls_openssl.h"
#ifdef OPENSSL_IS_BORINGSSL
typedef struct {
	X509_ALGOR *hashAlgorithm;
	ASN1_OCTET_STRING *issuerNameHash;
	ASN1_OCTET_STRING *issuerKeyHash;
	ASN1_INTEGER *serialNumber;
} CertID;
typedef struct {
	ASN1_OBJECT *responseType;
	ASN1_OCTET_STRING *response;
} ResponseBytes;
typedef struct {
	ASN1_ENUMERATED *responseStatus;
	ResponseBytes *responseBytes;
} OCSPResponse;
typedef struct {
	int type;
	union {
		X509_NAME *byName;
		ASN1_OCTET_STRING *byKey;
	} value;
typedef struct {
	ASN1_GENERALIZEDTIME *revocationTime;
	ASN1_ENUMERATED *revocationReason;
} RevokedInfo;
typedef struct {
	int type;
	union {
		ASN1_NULL *good;
		RevokedInfo *revoked;
		ASN1_NULL *unknown;
	} value;
typedef struct {
	CertID *certID;
	CertStatus *certStatus;
	ASN1_GENERALIZEDTIME *thisUpdate;
	ASN1_GENERALIZEDTIME *nextUpdate;
	STACK_OF(X509_EXTENSION) *singleExtensions;
} SingleResponse;
typedef struct {
	ASN1_INTEGER *version;
	ResponderID *responderID;
	ASN1_GENERALIZEDTIME *producedAt;
	STACK_OF(SingleResponse) *responses;
	STACK_OF(X509_EXTENSION) *responseExtensions;
} ResponseData;
typedef struct {
	ResponseData *tbsResponseData;
	X509_ALGOR *signatureAlgorithm;
	ASN1_BIT_STRING *signature;
	STACK_OF(X509) *certs;
} BasicOCSPResponse;
#define sk_SingleResponse_num(sk) \
#define sk_SingleResponse_value(sk, i) \
#endif /* OPENSSL_IS_BORINGSSL */
