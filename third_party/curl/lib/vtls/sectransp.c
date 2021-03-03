#include "curl_setup.h"
#include "urldata.h" /* for the Curl_easy definition */
#include "curl_base64.h"
#include "strtok.h"
#include "multiif.h"
#ifdef USE_SECTRANSP
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wtautological-pointer-compare"
#endif /* __clang__ */
#include <limits.h>
#include <Security/Security.h>
#include <Security/SecureTransport.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CommonCrypto/CommonDigest.h>
#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
#if MAC_OS_X_VERSION_MAX_ALLOWED < 1050
#error "The Secure Transport back-end requires Leopard or later."
#endif /* MAC_OS_X_VERSION_MAX_ALLOWED < 1050 */
#define CURL_BUILD_IOS 0
#define CURL_BUILD_IOS_7 0
#define CURL_BUILD_IOS_9 0
#define CURL_BUILD_IOS_11 0
#define CURL_BUILD_MAC 1
#define CURL_BUILD_MAC_10_5 MAC_OS_X_VERSION_MAX_ALLOWED >= 1050
#define CURL_BUILD_MAC_10_6 MAC_OS_X_VERSION_MAX_ALLOWED >= 1060
#define CURL_BUILD_MAC_10_7 MAC_OS_X_VERSION_MAX_ALLOWED >= 1070
#define CURL_BUILD_MAC_10_8 MAC_OS_X_VERSION_MAX_ALLOWED >= 1080
#define CURL_BUILD_MAC_10_9 MAC_OS_X_VERSION_MAX_ALLOWED >= 1090
#define CURL_BUILD_MAC_10_11 MAC_OS_X_VERSION_MAX_ALLOWED >= 101100
#define CURL_BUILD_MAC_10_13 MAC_OS_X_VERSION_MAX_ALLOWED >= 101300
#define CURL_SUPPORT_MAC_10_5 MAC_OS_X_VERSION_MIN_REQUIRED <= 1050
#define CURL_SUPPORT_MAC_10_6 MAC_OS_X_VERSION_MIN_REQUIRED <= 1060
#define CURL_SUPPORT_MAC_10_7 MAC_OS_X_VERSION_MIN_REQUIRED <= 1070
#define CURL_SUPPORT_MAC_10_8 MAC_OS_X_VERSION_MIN_REQUIRED <= 1080
#define CURL_SUPPORT_MAC_10_9 MAC_OS_X_VERSION_MIN_REQUIRED <= 1090
#elif TARGET_OS_EMBEDDED || TARGET_OS_IPHONE
#define CURL_BUILD_IOS 1
#define CURL_BUILD_IOS_7 __IPHONE_OS_VERSION_MAX_ALLOWED >= 70000
#define CURL_BUILD_IOS_9 __IPHONE_OS_VERSION_MAX_ALLOWED >= 90000
#define CURL_BUILD_IOS_11 __IPHONE_OS_VERSION_MAX_ALLOWED >= 110000
#define CURL_BUILD_MAC 0
#define CURL_BUILD_MAC_10_5 0
#define CURL_BUILD_MAC_10_6 0
#define CURL_BUILD_MAC_10_7 0
#define CURL_BUILD_MAC_10_8 0
#define CURL_BUILD_MAC_10_9 0
#define CURL_BUILD_MAC_10_11 0
#define CURL_BUILD_MAC_10_13 0
#define CURL_SUPPORT_MAC_10_5 0
#define CURL_SUPPORT_MAC_10_6 0
#define CURL_SUPPORT_MAC_10_7 0
#define CURL_SUPPORT_MAC_10_8 0
#define CURL_SUPPORT_MAC_10_9 0
#else
#error "The Secure Transport back-end requires iOS or macOS."
#endif /* (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)) */
#if CURL_BUILD_MAC
#include <sys/sysctl.h>
#endif /* CURL_BUILD_MAC */
#include "urldata.h"
#include "sendf.h"
#include "inet_pton.h"
#include "connect.h"
#include "select.h"
#include "vtls.h"
#include "sectransp.h"
#include "curl_printf.h"
#include "strdup.h"
#include "curl_memory.h"
#include "memdebug.h"
#define ioErr -36
#define paramErr -50
#define BACKEND connssl->backend
#if ((TARGET_OS_IPHONE && __IPHONE_OS_VERSION_MIN_REQUIRED >= 100000) || \
#define SECTRANSP_PINNEDPUBKEY_V1 1
#endif
#if (!TARGET_OS_IPHONE && __MAC_OS_X_VERSION_MIN_REQUIRED >= 1070)
#define SECTRANSP_PINNEDPUBKEY_V2 1
#endif
#if defined(SECTRANSP_PINNEDPUBKEY_V1) || defined(SECTRANSP_PINNEDPUBKEY_V2)
#define SECTRANSP_PINNEDPUBKEY 1
#endif /* SECTRANSP_PINNEDPUBKEY */
#ifdef SECTRANSP_PINNEDPUBKEY
#ifdef SECTRANSP_PINNEDPUBKEY_V1
#endif /* SECTRANSP_PINNEDPUBKEY_V1 */
#endif /* SECTRANSP_PINNEDPUBKEY */
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#if CURL_BUILD_MAC_10_6 || CURL_BUILD_IOS
#endif /* CURL_BUILD_MAC_10_6 || CURL_BUILD_IOS */
#if CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS
#else
#endif /* CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS */
#if CURL_BUILD_MAC_10_9 || CURL_BUILD_IOS_7
#endif /* CURL_BUILD_MAC_10_9 || CURL_BUILD_IOS_7 */
#if CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11
#endif /* CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11 */
#endif /* !CURL_DISABLE_VERBOSE_STRINGS */
#if CURL_BUILD_MAC
#endif /* CURL_BUILD_MAC */
#if CURL_BUILD_IOS
#else
#if CURL_BUILD_MAC_10_7
#endif /* CURL_BUILD_MAC_10_7 */
#if CURL_BUILD_MAC_10_6
#endif /* CURL_BUILD_MAC_10_6 */
#endif /* CURL_BUILD_IOS */
#if CURL_SUPPORT_MAC_10_6
#endif /* CURL_SUPPORT_MAC_10_6 */
#if CURL_BUILD_MAC_10_7 || CURL_BUILD_IOS
#if CURL_BUILD_IOS
#elif CURL_BUILD_MAC_10_7
#endif
#if CURL_SUPPORT_MAC_10_6
#endif /* CURL_SUPPORT_MAC_10_6 */
#elif CURL_SUPPORT_MAC_10_6
#endif /* CURL_BUILD_MAC_10_7 || CURL_BUILD_IOS */
#if CURL_BUILD_MAC_10_7 || CURL_BUILD_IOS
#if CURL_BUILD_IOS
#elif CURL_BUILD_MAC_10_7
#endif
#if CURL_BUILD_MAC_10_7
#endif
#endif /* CURL_BUILD_MAC_10_7 || CURL_BUILD_IOS */
#if CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS
#if (CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11) && HAVE_BUILTIN_AVAILABLE == 1
#endif /* (CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11) &&
#endif
#if (CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11) && HAVE_BUILTIN_AVAILABLE == 1
#else
#endif /* (CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11) &&
#if CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS
#if CURL_SUPPORT_MAC_10_8
#endif  /* CURL_SUPPORT_MAC_10_8 */
#endif  /* CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS */
#ifdef ENABLE_IPV6
#else
#endif /* ENABLE_IPV6 */
#if CURL_BUILD_MAC
#endif /* CURL_BUILD_MAC */
#if CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS
#if CURL_SUPPORT_MAC_10_8
#endif /* CURL_SUPPORT_MAC_10_8 */
#else
#endif /* CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS */
#if CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS
#if (CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11) && HAVE_BUILTIN_AVAILABLE == 1
#else
#endif /* (CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11) &&
#if CURL_SUPPORT_MAC_10_8
#endif  /* CURL_SUPPORT_MAC_10_8 */
#else
#endif /* CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS */
#if (CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11) && HAVE_BUILTIN_AVAILABLE == 1
#ifdef USE_NGHTTP2
#endif
#endif
#if CURL_BUILD_MAC_10_6 || CURL_BUILD_IOS
#if CURL_BUILD_MAC
#else
#endif /* CURL_BUILD_MAC */
#if CURL_SUPPORT_MAC_10_8
#endif /* CURL_SUPPORT_MAC_10_8 */
#else
#endif /* CURL_BUILD_MAC_10_6 || CURL_BUILD_IOS */
#if CURL_BUILD_MAC
#endif /* CURL_BUILD_MAC */
#if CURL_BUILD_MAC_10_9 || CURL_BUILD_IOS_7
#endif /* CURL_BUILD_MAC_10_9 || CURL_BUILD_IOS_7 */
#ifdef SECTRANSP_PINNEDPUBKEY
#ifdef SECTRANSP_PINNEDPUBKEY_V1
#elif SECTRANSP_PINNEDPUBKEY_V2
#endif /* SECTRANSP_PINNEDPUBKEY_V2 */
#ifdef SECTRANSP_PINNEDPUBKEY_V1
#elif SECTRANSP_PINNEDPUBKEY_V2
#endif /* SECTRANSP_PINNEDPUBKEY_V2 */
#endif /* SECTRANSP_PINNEDPUBKEY */
#if CURL_BUILD_MAC_10_11 || CURL_BUILD_IOS_9
#endif
#if CURL_BUILD_MAC_10_11 || CURL_BUILD_IOS_9
#endif
#if CURL_BUILD_MAC_10_6
#endif
#if CURL_BUILD_MAC_10_9
#endif
#ifdef SECTRANSP_PINNEDPUBKEY
#endif /* SECTRANSP_PINNEDPUBKEY */
#if CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS
#endif /* CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS */
#if CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11
#endif /* CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11 */
#if(CURL_BUILD_MAC_10_13 || CURL_BUILD_IOS_11) && HAVE_BUILTIN_AVAILABLE == 1
#ifdef USE_NGHTTP2
#endif
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#if CURL_BUILD_MAC_10_7 || CURL_BUILD_IOS
#if CURL_BUILD_IOS
#pragma unused(server_certs)
#else
#pragma unused(server_certs)
#if CURL_SUPPORT_MAC_10_8
#endif /* CURL_SUPPORT_MAC_10_8 */
#endif /* CURL_BUILD_IOS */
#else
#pragma unused(trust)
#endif /* CURL_BUILD_MAC_10_7 || CURL_BUILD_IOS */
#endif /* !CURL_DISABLE_VERBOSE_STRINGS */
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#if CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS
#if CURL_SUPPORT_MAC_10_8
#endif  /* CURL_SUPPORT_MAC_10_8 */
#else
#endif /* CURL_BUILD_MAC_10_8 || CURL_BUILD_IOS */
#ifndef CURL_DISABLE_FTP
#endif
static void Curl_sectransp_session_free(void *ptr)
{
  /* ST, as of iOS 5 and Mountain Lion, has no public method of deleting a
     cached session ID inside the Security framework. There is a private
     function that does this, but I don't want to have to explain to you why I
     got your application rejected from the App Store due to the use of a
     private API, so the best we can do is free up our own char array that we
     created way back in sectransp_connect_step1... */
  Curl_safefree(ptr);
}
#if CURL_BUILD_MAC_10_9 || CURL_BUILD_IOS_7
#endif
#ifdef SECTRANSP_PINNEDPUBKEY
#else
#endif /* SECTRANSP_PINNEDPUBKEY */
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif /* USE_SECTRANSP */
