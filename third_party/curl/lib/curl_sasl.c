#include "curl_setup.h"
#if !defined(CURL_DISABLE_IMAP) || !defined(CURL_DISABLE_SMTP) || \
#include <curl/curl.h>
#include "urldata.h"
#include "curl_base64.h"
#include "curl_md5.h"
#include "vauth/vauth.h"
#include "vtls/vtls.h"
#include "curl_hmac.h"
#include "curl_sasl.h"
#include "warnless.h"
#include "strtok.h"
#include "sendf.h"
#include "non-ascii.h" /* included for Curl_convert_... prototypes */
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#if defined(USE_KERBEROS5)
#endif
#if defined(USE_NTLM)
#endif
#if !defined(USE_KERBEROS5) && !defined(USE_NTLM)
#endif
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
#else
#endif
#if defined(USE_KERBEROS5) || defined(USE_NTLM)
#endif
#if defined(USE_KERBEROS5)
#endif
#ifndef CURL_DISABLE_CRYPTO_AUTH
#endif
#ifdef USE_NTLM
#endif
#if !defined(CURL_DISABLE_CRYPTO_AUTH)
#endif
#if !defined(CURL_DISABLE_CRYPTO_AUTH) || defined(USE_KERBEROS5) || \
#endif
#ifndef CURL_DISABLE_CRYPTO_AUTH
#endif
#ifdef USE_NTLM
#endif
#if defined(USE_KERBEROS5)
#endif
#endif /* protocols are enabled that use SASL */
