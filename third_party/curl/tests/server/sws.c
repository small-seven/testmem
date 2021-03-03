#include "server_setup.h"
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
#ifdef HAVE_NETINET_TCP_H
#include <netinet/tcp.h> /* for TCP_NODELAY */
#endif
#define ENABLE_CURLX_PRINTF
#include "curlx.h" /* from the private lib dir */
#include "getpart.h"
#include "inet_pton.h"
#include "util.h"
#include "server_sockaddr.h"
#include "memdebug.h"
#ifdef USE_WINSOCK
#undef  EINTR
#define EINTR    4 /* errno.h value */
#undef  EAGAIN
#define EAGAIN  11 /* errno.h value */
#undef  ERANGE
#define ERANGE  34 /* errno.h value */
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef USE_UNIX_SOCKETS
#endif
#define REQBUFSIZ 150000
#define REQBUFSIZ_TXT "149999"
#define RCMD_NORMALREQ 0 /* default request, use the tests file normally */
#define RCMD_IDLE      1 /* told to sit idle */
#define RCMD_STREAM    2 /* told to stream */
#define MAX_SOCKETS 1024
#define DEFAULT_PORT 8999
#ifndef DEFAULT_LOGFILE
#define DEFAULT_LOGFILE "log/sws.log"
#endif
#define SWSVERSION "curl test suite HTTP server/0.1"
#define REQUEST_DUMP  "log/server.input"
#define RESPONSE_DUMP "log/server.response"
#define REQUEST_PROXY_DUMP  "log/proxy.input"
#define RESPONSE_PROXY_DUMP "log/proxy.response"
#define MAXDOCNAMELEN 140000
#define MAXDOCNAMELEN_TXT "139999"
#define REQUEST_KEYWORD_SIZE 256
#define REQUEST_KEYWORD_SIZE_TXT "255"
#define CMD_AUTH_REQUIRED "auth_required"
#define CMD_IDLE "idle"
#define CMD_STREAM "stream"
#define CMD_CONNECTIONMONITOR "connection-monitor"
#define CMD_UPGRADE "upgrade"
#define CMD_SWSCLOSE "swsclose"
#define CMD_NOEXPECT "no-expect"
#define END_OF_HEADERS "\r\n\r\n"
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

#ifdef SIGTERM
static SIGHANDLER_T old_sigterm_handler = SIG_ERR;
#endif

#if defined(SIGBREAK) && defined(WIN32)
static SIGHANDLER_T old_sigbreak_handler = SIG_ERR;
#endif

/* var which if set indicates that the program should finish execution */

SIG_ATOMIC_T got_exit_signal = 0;

/* if next is set indicates the first signal handled in exit_signal_handler */

static volatile int exit_signal = 0;

/* work around for handling trailing headers */
static int already_recv_zeroed_chunk = FALSE;

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
#ifdef SIGTERM
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
#ifdef SIGTERM
#endif
#if defined(SIGBREAK) && defined(WIN32)
#endif
#ifdef ENABLE_IPV6
#endif
#define STREAMTHIS "a string to stream 01234567890\n"
#ifdef ENABLE_IPV6
#endif
#ifdef TCP_NODELAY
#endif
#ifdef ENABLE_IPV6
#endif /* ENABLE_IPV6 */
#ifdef USE_UNIX_SOCKETS
#endif /* USE_UNIX_SOCKETS */
#define data_or_ctrl(x) ((x)?"DATA":"CTRL")
#define CTRL  0
#define DATA  1
#ifdef TCP_NODELAY
#endif
#ifdef TCP_NODELAY
#endif
#ifdef USE_UNIX_SOCKETS
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef USE_UNIX_SOCKETS
#endif
#ifdef ENABLE_IPV6
#endif
#ifdef USE_UNIX_SOCKETS
#endif
#ifdef WIN32
#endif
#ifdef ENABLE_IPV6
#endif /* ENABLE_IPV6 */
#ifdef USE_UNIX_SOCKETS
#endif /* USE_UNIX_SOCKETS */
#ifdef USE_UNIX_SOCKETS
#endif
#ifdef USE_UNIX_SOCKETS
#endif
