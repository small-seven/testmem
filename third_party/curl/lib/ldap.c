#include "curl_setup.h"
#if !defined(CURL_DISABLE_LDAP) && !defined(USE_OPENLDAP)
#ifdef USE_WIN32_LDAP           /* Use Windows LDAP implementation. */
# include <winldap.h>
# ifndef LDAP_VENDOR_NAME
#  error Your Platform SDK is NOT sufficient for LDAP support! \
# else
#  include <winber.h>
# endif
#else
# define LDAP_DEPRECATED 1      /* Be sure ldap_init() is defined. */
# ifdef HAVE_LBER_H
#  include <lber.h>
# endif
# include <ldap.h>
# if (defined(HAVE_LDAP_SSL) && defined(HAVE_LDAP_SSL_H))
#  include <ldap_ssl.h>
# endif /* HAVE_LDAP_SSL && HAVE_LDAP_SSL_H */
#endif
#include "urldata.h"
#include <curl/curl.h>
#include "sendf.h"
#include "escape.h"
#include "progress.h"
#include "transfer.h"
#include "strcase.h"
#include "strtok.h"
#include "curl_ldap.h"
#include "curl_multibyte.h"
#include "curl_base64.h"
#include "connect.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifndef HAVE_LDAP_URL_PARSE
typedef struct {
  char   *lud_host;
  int     lud_port;
#if defined(USE_WIN32_LDAP)
  TCHAR  *lud_dn;
  TCHAR **lud_attrs;
#else
  char   *lud_dn;
  char  **lud_attrs;
#endif
  int     lud_scope;
#if defined(USE_WIN32_LDAP)
  TCHAR  *lud_filter;
#else
  char   *lud_filter;
#endif
  char  **lud_exts;
  size_t    lud_attrs_dups; /* how many were dup'ed, this field is not in the
                               "real" struct so can only be used in code
                               without HAVE_LDAP_URL_PARSE defined */
} CURL_LDAPURLDesc;
#undef LDAPURLDesc
#define LDAPURLDesc             CURL_LDAPURLDesc
#undef ldap_free_urldesc
#define ldap_free_urldesc       _ldap_free_urldesc
#endif
#ifdef DEBUG_LDAP
#else
#endif
#if defined(USE_WIN32_LDAP) && defined(ldap_err2string)
#undef ldap_err2string
#define ldap_err2string ldap_err2stringA
#endif
#ifdef HAVE_LDAP_SSL
#endif
#if defined(USE_WIN32_LDAP)
#if defined(USE_WINDOWS_SSPI)
#if defined(USE_SPNEGO)
#endif
#if defined(USE_NTLM)
#endif
#if !defined(CURL_DISABLE_CRYPTO_AUTH)
#endif
#endif /* #if defined(USE_WINDOWS_SSPI) */
#if defined(USE_WINDOWS_SSPI)
#endif
#endif /* #if defined(USE_WIN32_LDAP) */
#ifdef LDAP_OPT_NETWORK_TIMEOUT
#endif
#if defined(USE_WIN32_LDAP)
#else
#endif
#ifdef HAVE_LDAP_URL_PARSE
#else
#endif
#if defined(USE_WIN32_LDAP)
#else
#endif
#ifdef LDAP_OPT_NETWORK_TIMEOUT
#endif
#ifdef HAVE_LDAP_SSL
#ifdef USE_WIN32_LDAP
#else
#if defined(CURL_HAS_NOVELL_LDAPSDK)
#elif defined(LDAP_OPT_X_TLS)
#else
#endif
#endif
#endif /* CURL_LDAP_USE_SSL */
#ifdef USE_WIN32_LDAP
#endif
#ifdef USE_WIN32_LDAP
#else
#endif
#ifdef USE_WIN32_LDAP
#else
#endif
#ifdef USE_WIN32_LDAP
#else
#endif
#if defined(USE_WIN32_LDAP)
#else
#endif
#if defined(USE_WIN32_LDAP)
#else
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#else
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(USE_WIN32_LDAP)
#endif
#if defined(HAVE_LDAP_SSL) && defined(CURL_HAS_NOVELL_LDAPSDK)
#endif /* HAVE_LDAP_SSL && CURL_HAS_NOVELL_LDAPSDK */
#if defined(USE_WIN32_LDAP)
#endif
#ifdef DEBUG_LDAP
#endif
#ifndef HAVE_LDAP_URL_PARSE
#if defined(USE_WIN32_LDAP)
#else
#endif
#if defined(USE_WIN32_LDAP)
#else
#endif
#if defined(USE_WIN32_LDAP)
#else
#endif
#if defined(USE_WIN32_LDAP)
#else
#endif
#endif  /* !HAVE_LDAP_URL_PARSE */
#endif  /* !CURL_DISABLE_LDAP && !USE_OPENLDAP */
