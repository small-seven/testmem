#include "includes.h"
#include <curl/curl.h>
#ifdef EAP_TLS_OPENSSL
#include <openssl/ssl.h>
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include <openssl/x509v3.h>
#ifdef SSL_set_tlsext_status_type
#ifndef OPENSSL_NO_TLSEXT
#define HAVE_OCSP
#include <openssl/err.h>
#include <openssl/ocsp.h>
#endif /* OPENSSL_NO_TLSEXT */
#endif /* SSL_set_tlsext_status_type */
#endif /* EAP_TLS_OPENSSL */
#include "common.h"
#include "xml-utils.h"
#include "http-utils.h"
#ifdef EAP_TLS_OPENSSL
#include "crypto/tls_openssl.h"
#endif /* EAP_TLS_OPENSSL */
#if OPENSSL_VERSION_NUMBER < 0x10100000L
#endif /* OpenSSL < 1.1.0 */
#ifdef EAP_TLS_OPENSSL
typedef struct {
	X509_ALGOR *hashAlg;
	ASN1_OCTET_STRING *hashValue;
} HashAlgAndValue;
typedef struct {
	STACK_OF(HashAlgAndValue) *refStructHash;
	STACK_OF(ASN1_IA5STRING) *refStructURI;
} LogotypeReference;
typedef struct {
	ASN1_IA5STRING *mediaType;
	STACK_OF(HashAlgAndValue) *logotypeHash;
	STACK_OF(ASN1_IA5STRING) *logotypeURI;
} LogotypeDetails;
typedef struct {
	int type;
	union {
		ASN1_INTEGER *numBits;
		ASN1_INTEGER *tableSize;
	} d;
typedef struct {
	ASN1_INTEGER *type; /* LogotypeImageType ::= INTEGER */
	ASN1_INTEGER *fileSize;
	ASN1_INTEGER *xSize;
	ASN1_INTEGER *ySize;
	LogotypeImageResolution *resolution;
	ASN1_IA5STRING *language;
} LogotypeImageInfo;
typedef struct {
	LogotypeDetails *imageDetails;
	LogotypeImageInfo *imageInfo;
} LogotypeImage;
typedef struct {
	ASN1_INTEGER *fileSize;
	ASN1_INTEGER *playTime;
	ASN1_INTEGER *channels;
	ASN1_INTEGER *sampleRate;
	ASN1_IA5STRING *language;
} LogotypeAudioInfo;
typedef struct {
	LogotypeDetails *audioDetails;
	LogotypeAudioInfo *audioInfo;
} LogotypeAudio;
typedef struct {
	STACK_OF(LogotypeImage) *image;
	STACK_OF(LogotypeAudio) *audio;
} LogotypeData;
typedef struct {
	int type;
	union {
		LogotypeData *direct;
		LogotypeReference *indirect;
	} d;
typedef struct {
	ASN1_OBJECT *logotypeType;
	LogotypeInfo *info;
} OtherLogotypeInfo;
typedef struct {
	STACK_OF(LogotypeInfo) *communityLogos;
	LogotypeInfo *issuerLogo;
	LogotypeInfo *subjectLogo;
	STACK_OF(OtherLogotypeInfo) *otherLogos;
} LogotypeExtn;
#ifdef OPENSSL_IS_BORINGSSL
#define sk_LogotypeInfo_num(st) \
#define sk_LogotypeInfo_value(st, i) (LogotypeInfo *) \
#define sk_LogotypeImage_num(st) \
#define sk_LogotypeImage_value(st, i) (LogotypeImage *) \
#define sk_LogotypeAudio_num(st) \
#define sk_LogotypeAudio_value(st, i) (LogotypeAudio *) \
#define sk_HashAlgAndValue_num(st) \
#define sk_HashAlgAndValue_value(st, i) (HashAlgAndValue *) \
#define sk_ASN1_IA5STRING_num(st) \
#define sk_ASN1_IA5STRING_value(st, i) (ASN1_IA5STRING *) \
#else /* OPENSSL_IS_BORINGSSL */
#if OPENSSL_VERSION_NUMBER < 0x10100000L
#define sk_LogotypeInfo_num(st) SKM_sk_num(LogotypeInfo, (st))
#define sk_LogotypeInfo_value(st, i) SKM_sk_value(LogotypeInfo, (st), (i))
#define sk_LogotypeImage_num(st) SKM_sk_num(LogotypeImage, (st))
#define sk_LogotypeImage_value(st, i) SKM_sk_value(LogotypeImage, (st), (i))
#define sk_LogotypeAudio_num(st) SKM_sk_num(LogotypeAudio, (st))
#define sk_LogotypeAudio_value(st, i) SKM_sk_value(LogotypeAudio, (st), (i))
#define sk_HashAlgAndValue_num(st) SKM_sk_num(HashAlgAndValue, (st))
#define sk_HashAlgAndValue_value(st, i) SKM_sk_value(HashAlgAndValue, (st), (i))
#define sk_ASN1_IA5STRING_num(st) SKM_sk_num(ASN1_IA5STRING, (st))
#define sk_ASN1_IA5STRING_value(st, i) SKM_sk_value(ASN1_IA5STRING, (st), (i))
#else
#endif
#endif /* OPENSSL_IS_BORINGSSL */
static void parse_cert_free(struct http_cert *hcert, GENERAL_NAMES *names)
{
	unsigned int i;

	for (i = 0; i < hcert->num_dnsname; i++)
		OPENSSL_free(hcert->dnsname[i]);
	os_free(hcert->dnsname);

	for (i = 0; i < hcert->num_othername; i++)
		os_free(hcert->othername[i].oid);
	os_free(hcert->othername);

	for (i = 0; i < hcert->num_logo; i++) {
		os_free(hcert->logo[i].alg_oid);
		os_free(hcert->logo[i].hash);
		os_free(hcert->logo[i].uri);
	}
	os_free(hcert->logo);

	sk_GENERAL_NAME_pop_free(names, GENERAL_NAME_free);
}
#ifdef OPENSSL_IS_BORINGSSL
#endif /* OPENSSL_IS_BORINGSSL */
#ifdef HAVE_OCSP
#if OPENSSL_VERSION_NUMBER < 0x10100000L
#endif /* OpenSSL < 1.1.0 */
#endif /* HAVE_OCSP */
#ifdef HAVE_OCSP
#if OPENSSL_VERSION_NUMBER < 0x10100000L
#endif /* OpenSSL < 1.1.0 */
#endif /* HAVE_OCSP */
#endif /* EAP_TLS_OPENSSL */
#ifdef EAP_TLS_OPENSSL
#else /* EAP_TLS_OPENSSL */
#endif /* EAP_TLS_OPENSSL */
#ifdef EAP_TLS_OPENSSL
#if defined(OPENSSL_IS_BORINGSSL) || (OPENSSL_VERSION_NUMBER >= 0x10100000L)
#endif /* OPENSSL_IS_BORINGSSL */
#endif /* EAP_TLS_OPENSSL */
