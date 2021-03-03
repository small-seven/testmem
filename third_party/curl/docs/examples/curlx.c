#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <openssl/x509v3.h>
#include <openssl/x509_vfy.h>
#include <openssl/crypto.h>
#include <openssl/lhash.h>
#include <openssl/objects.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/pkcs12.h>
#include <openssl/bio.h>
#include <openssl/ssl.h>
#define ZERO_NULL 0
typedef struct sslctxparm_st {
  unsigned char *p12file;
  const char *pst;
  PKCS12 *p12;
  EVP_PKEY *pkey;
  X509 *usercert;
  STACK_OF(X509) * ca;
  CURL *curl;
  BIO *errorbio;
  int accesstype;
  int verbose;

} sslctxparm;
