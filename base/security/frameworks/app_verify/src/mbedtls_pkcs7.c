#include "mbedtls_pkcs7.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "app_common.h"
#include "mbedtls/platform.h" // for mbedtls_calloc
#include "securec.h"
#define VERIFY_BUF_LEN 512
#define MAX_SIG_SIZE 1024
#ifndef MBEDTLS_OID_PKCS7
#define MBEDTLS_OID_PKCS7 MBEDTLS_OID_PKCS "\x07"
#endif
#ifndef MBEDTLS_OID_PKCS7_DATA
#define MBEDTLS_OID_PKCS7_DATA MBEDTLS_OID_PKCS7 "\x01"
#endif
#ifndef MBEDTLS_OID_PKCS7_SIGNED_DATA
#define MBEDTLS_OID_PKCS7_SIGNED_DATA MBEDTLS_OID_PKCS7 "\x02"
#endif
#ifndef MBEDTLS_OID_PKCS9_MSG_DIGEST
#define MBEDTLS_OID_PKCS9_MSG_DIGEST MBEDTLS_OID_PKCS9 "\x04"
#endif
#define PKCS7_SIGNED_DATA_VERSION 1
#define PEM_FORMAT_SINGED_DATA 1
#define DER_FORMAT_SINGED_DATA 2
#define PKCS7_ERR_RETURN_WITH_LOG(rc) \
#define DIFF_NUM 32
static void *Pkcs7Calloc(size_t nmemb, size_t size)
{
    return calloc(nmemb, size);
}
static void Pkcs7Free(void *ptr)
{
    free(ptr);
}
static void FreeSignedDataDigestAlgs(Pkcs7 *pkcs7)
{
    DigestAlgId *alg = pkcs7->signedData.digestAlgIds.next;
    DigestAlgId *next = NULL;

    while (alg != NULL) {
        next = alg->next;
        Pkcs7Free(alg);
        alg = next;
    }
    pkcs7->signedData.digestAlgIds.next = NULL;
}
static void FreeSignerCerts(SignerInfo *signer)
{
    if (signer->certPath.crt != NULL) {
        mbedtls_x509_crt_free(signer->certPath.crt);
        mbedtls_free(signer->certPath.crt);
        signer->certPath.crt = NULL;
    }
}
static void FreeSignerIssuer(SignerInfo *signer)
{
    mbedtls_x509_name *name_cur = NULL;
    mbedtls_x509_name *name_prv = NULL;
    name_cur = signer->issuer.next;
    while (name_cur != NULL) {
        name_prv = name_cur;
        name_cur = name_cur->next;
        mbedtls_free(name_prv);
    }
    signer->issuer.next = NULL;
}
static void FreeSignersInfo(Pkcs7 *pkcs7)
{
    SignerInfo *signer = pkcs7->signedData.signers.next;
    SignerInfo *next = NULL;

    while (signer != NULL) {
        next = signer->next;
        FreeSignerCerts(signer);
        FreeSignerIssuer(signer);
        Pkcs7Free(signer);
        signer = next;
    }
    pkcs7->signedData.signers.next = NULL;
    FreeSignerCerts(&pkcs7->signedData.signers);
    FreeSignerIssuer(&pkcs7->signedData.signers);
}
static void FreeSignedDataCerts(Pkcs7 *pkcs7)
{
    if (pkcs7->signedData.certs != NULL) {
        mbedtls_x509_crt_free(pkcs7->signedData.certs);
        mbedtls_free(pkcs7->signedData.certs);
        pkcs7->signedData.certs = NULL;
    }
}
static void FreeSignedDataCrl(Pkcs7 *pkcs7)
{
    mbedtls_x509_crl_free(&pkcs7->signedData.crl);
    return;
}
void PKCS7_FreeAllSignersResolvedInfo(SignersResovedInfo *sri)
{
    if (sri == NULL) {
        return;
    }
    if (sri->signers != NULL) {
        Pkcs7Free(sri->signers);
        sri->signers = NULL;
    }
    Pkcs7Free(sri);
}
#ifdef PARSE_PEM_FORMAT_SIGNED_DATA
#endif
#ifdef PARSE_PEM_FORMAT_SIGNED_DATA
#endif
void PKCS7_FreeRes(Pkcs7 *pkcs7)
{
    if (pkcs7 == NULL) {
        return;
    }
    FreeSignedDataDigestAlgs(pkcs7);
    FreeSignersInfo(pkcs7);
    FreeSignedDataCerts(pkcs7);
    FreeSignedDataCrl(pkcs7);
    UnLoadRootCert();
    return;
}
