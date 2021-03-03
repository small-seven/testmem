#include "curl_setup.h"
#ifdef USE_NSS
#include "urldata.h"
#include "sendf.h"
#include "formdata.h" /* for the boundary function */
#include "url.h" /* for the ssl config check function */
#include "connect.h"
#include "strcase.h"
#include "select.h"
#include "vtls.h"
#include "llist.h"
#include "multiif.h"
#include "curl_printf.h"
#include "nssg.h"
#include <nspr.h>
#include <nss.h>
#include <ssl.h>
#include <sslerr.h>
#include <secerr.h>
#include <secmod.h>
#include <sslproto.h>
#include <prtypes.h>
#include <pk11pub.h>
#include <prio.h>
#include <secitem.h>
#include <secport.h>
#include <certdb.h>
#include <base64.h>
#include <cert.h>
#include <prerror.h>
#include <keyhi.h>         /* for SECKEY_DestroyPublicKey() */
#include <private/pprio.h> /* for PR_ImportTCPSocket */
#define NSSVERNUM ((NSS_VMAJOR<<16)|(NSS_VMINOR<<8)|NSS_VPATCH)
#if NSSVERNUM >= 0x030f00 /* 3.15.0 */
#include <ocsp.h>
#endif
#include "strcase.h"
#include "warnless.h"
#include "x509asn1.h"
#include "curl_memory.h"
#include "memdebug.h"
#define SSL_DIR "/etc/pki/nssdb"
#define SLOTSIZE 13
#define BACKEND connssl->backend
typedef struct {
  const char *name;
  int num;
} cipher_s;
#define PK11_SETATTRS(_attr, _idx, _type, _val, _len) do {  \
#define CERT_NewTempCertificate __CERT_NewTempCertificate
#define NUM_OF_CIPHERS sizeof(cipherlist)/sizeof(cipherlist[0])
#ifdef TLS_RSA_WITH_NULL_SHA256
#endif
#ifdef TLS_RSA_WITH_AES_128_GCM_SHA256
#endif
#ifdef TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384
#endif
#ifdef TLS_DHE_RSA_WITH_CHACHA20_POLY1305_SHA256
#endif
#ifdef TLS_AES_256_GCM_SHA384
#endif
#if defined(WIN32)
#elif defined(__APPLE__)
#else
#endif
#ifdef SSL_LIBRARY_VERSION_TLS_1_1
#endif
#ifdef SSL_LIBRARY_VERSION_TLS_1_2
#endif
#ifdef SSL_LIBRARY_VERSION_TLS_1_3
#endif
#ifdef HAVE_PK11_CREATEMANAGEDGENERICOBJECT
#else
#endif
#ifdef SSL_ENABLE_OCSP_STAPLING
#endif
#if NSSVERNUM >= 0x031a00 /* 3.26.0 */
#endif
#ifdef SSL_ENABLE_ALPN
#endif
#ifdef USE_NGHTTP2
#endif
#if NSSVERNUM >= 0x030f04 /* 3.15.4 */
#endif
#ifdef SSL_LIBRARY_VERSION_TLS_1_1
#else
#endif
#ifdef SSL_LIBRARY_VERSION_TLS_1_2
#else
#endif
#ifdef SSL_LIBRARY_VERSION_TLS_1_3
#else
#endif
#ifdef SSL_LIBRARY_VERSION_TLS_1_3
#elif defined SSL_LIBRARY_VERSION_TLS_1_2
#elif defined SSL_LIBRARY_VERSION_TLS_1_1
#else
#endif
#ifdef SSL_CBC_RANDOM_IV
#else
#endif
#ifdef SSL_ENABLE_OCSP_STAPLING
#endif
#ifdef SSL_ENABLE_NPN
#endif
#ifdef SSL_ENABLE_ALPN
#endif
#if NSSVERNUM >= 0x030f04 /* 3.15.4 */
#endif
#if defined(SSL_ENABLE_NPN) || defined(SSL_ENABLE_ALPN)
#ifdef USE_NGHTTP2
#endif
#endif
#ifdef SSL_ENABLE_OCSP_STAPLING
#else
#endif
#if NSSVERNUM >= 0x030f04 /* 3.15.4 */
#else
#endif
#endif /* USE_NSS */
