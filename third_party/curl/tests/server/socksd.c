#include "server_setup.h"
#include <stdlib.h>
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_NETINET_IN6_H
#include <netinet/in6.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#define ENABLE_CURLX_PRINTF
#include "curlx.h" /* from the private lib dir */
#include "getpart.h"
#include "inet_pton.h"
#include "util.h"
#include "server_sockaddr.h"
#include "warnless.h"
#include "memdebug.h"
#ifdef USE_WINSOCK
#undef  EINTR
#define EINTR    4 /* errno.h value */
#undef  EAGAIN
#define EAGAIN  11 /* errno.h value */
#undef  ENOMEM
#define ENOMEM  12 /* errno.h value */
#undef  EINVAL
#define EINVAL  22 /* errno.h value */
#endif
#define DEFAULT_PORT 8905
#ifndef DEFAULT_LOGFILE
#define DEFAULT_LOGFILE "log/socksd.log"
#endif
#ifndef DEFAULT_CONFIG
#define DEFAULT_CONFIG "socksd.config"
#endif
#define CONFIG_VERSION 5
#define CONFIG_NMETHODS_MIN 1 /* unauth, gssapi, auth */
#define CONFIG_NMETHODS_MAX 3
#define CONFIG_RESPONSEVERSION CONFIG_VERSION
#define CONFIG_RESPONSEMETHOD 0 /* no auth */
#define CONFIG_REQCMD 1 /* CONNECT */
#define CONFIG_PORT backendport
#define CONFIG_ADDR backendaddr
#define CONFIG_CONNECTREP 0
#ifdef ENABLE_IPV6
#endif
#ifndef HAVE_SIGINTERRUPT
#define siginterrupt(x,y) do {} while(0)
#endif
typedef RETSIGTYPE (*SIGHANDLER_T)(int);

#ifdef SIGHUP
static SIGHANDLER_T old_sighup_handler  = SIG_ERR;
#endif

#ifdef SIGPIPE
static SIGHANDLER_T old_sigpipe_handler = SIG_ERR;
#endif

#ifdef SIGALRM
static SIGHANDLER_T old_sigalrm_handler = SIG_ERR;
#endif

#ifdef SIGINT
static SIGHANDLER_T old_sigint_handler  = SIG_ERR;
#endif

#if defined(SIGBREAK) && defined(WIN32)
static SIGHANDLER_T old_sigbreak_handler = SIG_ERR;
#endif

/* var which if set indicates that the program should finish execution */

SIG_ATOMIC_T got_exit_signal = 0;

/* if next is set indicates the first signal handled in exit_signal_handler */

static volatile int exit_signal = 0;

/* signal handler that will be triggered to indicate that the program
  should finish its execution in a controlled manner as soon as possible.
  The first time this is called it will set got_exit_signal to one and
  store in exit_signal the signal that triggered its execution. */

static RETSIGTYPE exit_signal_handler(int signum)
{
  int old_errno = errno;
  if(got_exit_signal == 0) {
    got_exit_signal = 1;
    exit_signal = signum;
  }
#ifdef SIGHUP
#endif
#ifdef SIGPIPE
#endif
#ifdef SIGALRM
#endif
#ifdef SIGINT
#endif
#if defined(SIGBREAK) && defined(WIN32)
#endif
#ifdef SIGHUP
#endif
#ifdef SIGPIPE
#endif
#ifdef SIGALRM
#endif
#ifdef SIGINT
#endif
#if defined(SIGBREAK) && defined(WIN32)
#endif
#define SOCKS5_VERSION 0
#define SOCKS5_NMETHODS 1 /* number of methods that is listed */
#define SOCKS5_REQCMD 1
#define SOCKS5_RESERVED 2
#define SOCKS5_ATYP 3
#define SOCKS5_DSTADDR 4
#define SOCKS5_REP 1
#define SOCKS5_BNDADDR 4
#define SOCKS5_ULEN 1
#define SOCKS5_UNAME 2
#define SOCKS4_CD 1
#define SOCKS4_DSTPORT 2
#ifdef HAVE_GETPPID
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif /* ENABLE_IPV6 */
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#else
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef WIN32
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
