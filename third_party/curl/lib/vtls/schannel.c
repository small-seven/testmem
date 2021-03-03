#include "curl_setup.h"
#ifdef USE_SCHANNEL
#define EXPOSE_SCHANNEL_INTERNAL_STRUCTS
#ifndef USE_WINDOWS_SSPI
#  error "Can't compile SCHANNEL support without SSPI."
#endif
#include "schannel.h"
#include "vtls.h"
#include "sendf.h"
#include "connect.h" /* for the connect timeout */
#include "strerror.h"
#include "select.h" /* for the socket readyness */
#include "inet_pton.h" /* for IP addr SNI check */
#include "curl_multibyte.h"
#include "warnless.h"
#include "x509asn1.h"
#include "curl_printf.h"
#include "multiif.h"
#include "system_win32.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(_MSC_VER) && (_MSC_VER >= 1800) && !defined(_USING_V110_SDK71_)
#  define HAS_ALPN 1
#endif
#ifndef UNISP_NAME_A
#define UNISP_NAME_A "Microsoft Unified Security Protocol Provider"
#endif
#ifndef UNISP_NAME_W
#define UNISP_NAME_W L"Microsoft Unified Security Protocol Provider"
#endif
#ifndef UNISP_NAME
#ifdef UNICODE
#define UNISP_NAME  UNISP_NAME_W
#else
#define UNISP_NAME  UNISP_NAME_A
#endif
#endif
#if defined(CryptStringToBinary) && defined(CRYPT_STRING_HEX)
#define HAS_CLIENT_CERT_PATH
#endif
#ifdef HAS_CLIENT_CERT_PATH
#ifdef UNICODE
#define CURL_CERT_STORE_PROV_SYSTEM CERT_STORE_PROV_SYSTEM_W
#else
#define CURL_CERT_STORE_PROV_SYSTEM CERT_STORE_PROV_SYSTEM_A
#endif
#endif
#ifndef SP_PROT_SSL2_CLIENT
#define SP_PROT_SSL2_CLIENT             0x00000008
#endif
#ifndef SP_PROT_SSL3_CLIENT
#define SP_PROT_SSL3_CLIENT             0x00000008
#endif
#ifndef SP_PROT_TLS1_CLIENT
#define SP_PROT_TLS1_CLIENT             0x00000080
#endif
#ifndef SP_PROT_TLS1_0_CLIENT
#define SP_PROT_TLS1_0_CLIENT           SP_PROT_TLS1_CLIENT
#endif
#ifndef SP_PROT_TLS1_1_CLIENT
#define SP_PROT_TLS1_1_CLIENT           0x00000200
#endif
#ifndef SP_PROT_TLS1_2_CLIENT
#define SP_PROT_TLS1_2_CLIENT           0x00000800
#endif
#ifndef SECBUFFER_ALERT
#define SECBUFFER_ALERT                 17
#endif
#define CURL_SCHANNEL_BUFFER_INIT_SIZE   4096
#define CURL_SCHANNEL_BUFFER_FREE_SIZE   1024
#define CERT_THUMBPRINT_STR_LEN 40
#define CERT_THUMBPRINT_DATA_LEN 20
#ifndef CALG_SHA_256
#  define CALG_SHA_256 0x0000800c
#endif
#define BACKEND connssl->backend
#define LONGEST_ALG_ID 32
#define CIPHEROPTION(X) \
#ifdef CALG_NO_SIGN
#endif
#ifdef CALG_3DES_112
#endif
#ifdef CALG_DH_SF
#endif
#ifdef CALG_AGREEDKEY_ANY
#endif
#ifdef CALG_HUGHES_MD5
#endif
#ifdef CALG_TEK
#endif
#ifdef CALG_SSL3_MASTER
#endif
#ifdef CALG_SCHANNEL_MASTER_HASH
#endif
#ifdef CALG_SCHANNEL_MAC_KEY
#endif
#ifdef CALG_SCHANNEL_ENC_KEY
#endif
#ifdef CALG_PCT1_MASTER
#endif
#ifdef CALG_SSL2_MASTER
#endif
#ifdef CALG_TLS1_MASTER
#endif
#ifdef CALG_RC5
#endif
#ifdef CALG_HMAC
#endif
#if !defined(__W32API_MAJOR_VERSION) || \
#endif
#ifdef CALG_HASH_REPLACE_OWF
#endif
#ifdef CALG_AES_128
#endif
#ifdef CALG_AES_192
#endif
#ifdef CALG_AES_256
#endif
#ifdef CALG_AES
#endif
#ifdef CALG_SHA_256
#endif
#ifdef CALG_SHA_384
#endif
#ifdef CALG_SHA_512
#endif
#ifdef CALG_ECDH
#endif
#ifdef CALG_ECMQV
#endif
#ifdef CALG_ECDSA
#endif
#ifdef CALG_ECDH_EPHEM
#endif
#ifdef HAS_CLIENT_CERT_PATH
#endif
#ifdef HAS_ALPN
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef HAS_ALPN
#else
#endif
#ifdef _WIN32_WCE
#ifdef HAS_MANUAL_VERIFY_API
#else
#error "compiler too old to support requisite manual cert verify for Win CE"
#endif
#else
#ifdef HAS_MANUAL_VERIFY_API
#else
#endif
#endif
#ifdef HAS_MANUAL_VERIFY_API
#endif
#ifdef HAS_CLIENT_CERT_PATH
#else
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef HAS_ALPN
#ifdef USE_NGHTTP2
#endif
#else /* HAS_ALPN */
#endif
#ifdef HAS_MANUAL_VERIFY_API
#endif
typedef bool(*Read_crt_func)(const CERT_CONTEXT *ccert_context, void *arg);

static void
traverse_cert_store(const CERT_CONTEXT *context, Read_crt_func func,
                    void *arg)
{
  const CERT_CONTEXT *current_context = NULL;
  bool should_continue = true;
  while(should_continue &&
        (current_context = CertEnumCertificatesInStore(
          context->hCertStore,
          current_context)) != NULL)
    should_continue = func(current_context, arg);

  if(current_context)
    CertFreeCertificateContext(current_context);
}
#ifdef DEBUGBUILD
#endif
#ifdef HAS_ALPN
#endif
#ifdef HAS_ALPN
#ifdef USE_NGHTTP2
#endif
#endif
#ifdef SECPKG_ATTR_ENDPOINT_BINDINGS
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
static void Curl_schannel_session_free(void *ptr)
{
  /* this is expected to be called under sessionid lock */
  struct curl_schannel_cred *cred = ptr;

  cred->refcount--;
  if(cred->refcount == 0) {
    s_pSecFn->FreeCredentialsHandle(&cred->cred_handle);
    Curl_safefree(cred);
  }
}
#endif /* USE_SCHANNEL */
