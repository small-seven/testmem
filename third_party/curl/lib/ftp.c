#include "curl_setup.h"
#ifndef CURL_DISABLE_FTP
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef HAVE_UTSNAME_H
#include <sys/utsname.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef __VMS
#include <in.h>
#include <inet.h>
#endif
#if (defined(NETWARE) && defined(__NOVELL_LIBC__))
#undef in_addr_t
#define in_addr_t unsigned long
#endif
#include <curl/curl.h>
#include "urldata.h"
#include "sendf.h"
#include "if2ip.h"
#include "hostip.h"
#include "progress.h"
#include "transfer.h"
#include "escape.h"
#include "http.h" /* for HTTP proxy tunnel stuff */
#include "ftp.h"
#include "fileinfo.h"
#include "ftplistparser.h"
#include "curl_range.h"
#include "curl_sec.h"
#include "strtoofft.h"
#include "strcase.h"
#include "vtls/vtls.h"
#include "connect.h"
#include "strerror.h"
#include "inet_ntop.h"
#include "inet_pton.h"
#include "select.h"
#include "parsedate.h" /* for the week day and month names */
#include "sockaddr.h" /* required for Curl_sockaddr_storage */
#include "multiif.h"
#include "url.h"
#include "strcase.h"
#include "speedcheck.h"
#include "warnless.h"
#include "http_proxy.h"
#include "non-ascii.h"
#include "socks.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifndef NI_MAXHOST
#define NI_MAXHOST 1025
#endif
#ifndef INET_ADDRSTRLEN
#define INET_ADDRSTRLEN 16
#endif
#ifdef CURL_DISABLE_VERBOSE_STRINGS
#define ftp_pasv_verbose(a,b,c,d)  Curl_nop_stmt
#endif
#ifndef DEBUGBUILD
#define state(x,y) _state(x,y)
#else
#define state(x,y) _state(x,y,__LINE__)
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#define PPSENDF(x,y,z)  result = Curl_pp_sendf(x,y,z); \
#ifdef USE_SSL
#endif
#define CURL_FTP_HTTPSTYLE_HEAD 1
#ifdef ENABLE_IPV6
#else
#endif
#define STATUSCODE(line) (ISDIGIT(line[0]) && ISDIGIT(line[1]) &&       \
#define LASTLINE(line) (STATUSCODE(line) && (' ' == line[3]))
#ifdef HAVE_GSSAPI
#endif
#if defined(HAVE_GSSAPI)
#endif
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
#ifdef DEBUGBUILD
#endif
#if defined(DEBUGBUILD)
#if defined(CURL_DISABLE_VERBOSE_STRINGS)
#else
#endif
#endif
typedef enum {
  EPRT,
  PORT,
  DONE
} ftpport;
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#else
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef PF_INET6
#endif
#ifdef CURL_FTP_HTTPSTYLE_HEAD
#endif
#ifdef CURL_FTP_HTTPSTYLE_HEAD
#endif
#ifdef CURL_FTP_HTTPSTYLE_HEAD
#endif
#ifdef HAVE_GSSAPI
#endif
#ifdef _WIN32_WCE
#endif
#ifdef CURL_DO_LINEEND_CONV
#endif /* CURL_DO_LINEEND_CONV */
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#define SBUF_SIZE 1024
#ifdef HAVE_GSSAPI
#endif
#ifdef HAVE_GSSAPI
#endif
#ifdef HAVE_GSSAPI
#endif
#ifdef HAVE_GSSAPI
#endif
#endif /* CURL_DISABLE_FTP */
