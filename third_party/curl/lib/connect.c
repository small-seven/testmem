#include "curl_setup.h"
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h> /* <netinet/tcp.h> may need it */
#endif
#ifdef HAVE_SYS_UN_H
#include <sys/un.h> /* for sockaddr_un */
#endif
#ifdef HAVE_LINUX_TCP_H
#include <linux/tcp.h>
#elif defined(HAVE_NETINET_TCP_H)
#include <netinet/tcp.h>
#endif
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#if (defined(HAVE_IOCTL_FIONBIO) && defined(NETWARE))
#include <sys/filio.h>
#endif
#ifdef NETWARE
#undef in_addr_t
#define in_addr_t unsigned long
#endif
#ifdef __VMS
#include <in.h>
#include <inet.h>
#endif
#include "urldata.h"
#include "sendf.h"
#include "if2ip.h"
#include "strerror.h"
#include "connect.h"
#include "select.h"
#include "url.h" /* for Curl_safefree() */
#include "multiif.h"
#include "sockaddr.h" /* required for Curl_sockaddr_storage */
#include "inet_ntop.h"
#include "inet_pton.h"
#include "vtls/vtls.h" /* for Curl_ssl_check_cxn() */
#include "progress.h"
#include "warnless.h"
#include "conncache.h"
#include "multihandle.h"
#include "system_win32.h"
#include "quic.h"
#include "socks.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef __SYMBIAN32__
#undef SO_NOSIGPIPE
#endif
#if defined(__DragonFly__) || defined(HAVE_WINSOCK_H)
#define KEEPALIVE_FACTOR(x) (x *= 1000)
#else
#define KEEPALIVE_FACTOR(x)
#endif
#if defined(HAVE_WINSOCK2_H) && !defined(SIO_KEEPALIVE_VALS)
#define SIO_KEEPALIVE_VALS    _WSAIOW(IOC_VENDOR,4)
#endif
#if defined(SIO_KEEPALIVE_VALS)
#else
#ifdef TCP_KEEPIDLE
#endif
#ifdef TCP_KEEPINTVL
#endif
#ifdef TCP_KEEPALIVE
#endif
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef SO_BINDTODEVICE
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#ifdef HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID
#endif
#ifdef HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID
#endif
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef SO_ERROR
#ifdef WIN32
#ifdef _WIN32_WCE
#else
#endif
#endif
#ifdef _WIN32_WCE
#endif
#if defined(EBADIOCTL) && defined(__minix)
#endif
#else
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#if defined(HAVE_SYS_UN_H) && defined(AF_UNIX)
#else
#endif
#ifdef ENABLE_IPV6
#endif
#if defined(HAVE_SYS_UN_H) && defined(AF_UNIX)
#endif
#if defined(HAVE_GETPEERNAME) || defined(HAVE_GETSOCKNAME)
#ifdef HAVE_GETPEERNAME
#endif
#ifdef HAVE_GETSOCKNAME
#endif
#ifdef HAVE_GETPEERNAME
#endif
#ifdef HAVE_GETSOCKNAME
#endif
#else /* !HAVE_GETSOCKNAME && !HAVE_GETPEERNAME */
#endif
#ifndef CURL_DISABLE_PROXY
#else
#endif /* CURL_DISABLE_PROXY */
#ifdef ENABLE_QUIC
#endif
#ifdef mpeix
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_QUIC
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#ifdef WSAETIMEDOUT
#elif defined(ETIMEDOUT)
#endif
#if defined(TCP_NODELAY)
#if !defined(CURL_DISABLE_VERBOSE_STRINGS)
#else
#endif
#else
#endif
#ifdef SO_NOSIGPIPE
#else
#define nosigpipe(x,y) Curl_nop_stmt
#endif
#ifdef USE_WINSOCK
#define DETECT_OS_NONE 0
#define DETECT_OS_PREVISTA 1
#define DETECT_OS_VISTA_OR_LATER 2
#endif
#ifdef TCP_FASTOPEN_CONNECT
#endif
#ifdef ENABLE_IPV6
#else
#endif
#ifdef ENABLE_IPV6
#endif
#if defined(CONNECT_DATA_IDEMPOTENT) /* Darwin */
#  if defined(HAVE_BUILTIN_AVAILABLE)
#  else
#  endif /* HAVE_BUILTIN_AVAILABLE */
#elif defined(TCP_FASTOPEN_CONNECT) /* Linux >= 4.11 */
#elif defined(MSG_FASTOPEN) /* old Linux */
#endif
#ifdef ENABLE_QUIC
#endif
#if defined(EAGAIN)
#if (EAGAIN) != (EWOULDBLOCK)
#endif
#endif
#ifdef MSG_PEEK
#endif
#if defined(ENABLE_IPV6) && defined(HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID)
#endif
#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
#endif
