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
#include "util.h"
#include "server_sockaddr.h"
#include "memdebug.h"
#ifdef USE_WINSOCK
#undef  EINTR
#define EINTR    4 /* errno.h value */
#undef  ERANGE
#define ERANGE  34 /* errno.h value */
#endif
#ifdef ENABLE_IPV6
#endif
#define REQBUFSIZ 150000
#define REQBUFSIZ_TXT "149999"
#define RCMD_NORMALREQ 0 /* default request, use the tests file normally */
#define RCMD_IDLE      1 /* told to sit idle */
#define RCMD_STREAM    2 /* told to stream */
typedef enum {
  RPROT_NONE = 0,
  RPROT_RTSP = 1,
  RPROT_HTTP = 2
} reqprot_t;
#define SET_RTP_PKT_CHN(p,c)  ((p)[1] = (unsigned char)((c) & 0xFF))
#define SET_RTP_PKT_LEN(p,l) (((p)[2] = (unsigned char)(((l) >> 8) & 0xFF)), \
#define DEFAULT_PORT 8999
#ifndef DEFAULT_LOGFILE
#define DEFAULT_LOGFILE "log/rtspd.log"
#endif
#define RTSPDVERSION "curl test suite RTSP server/0.1"
#define REQUEST_DUMP  "log/server.input"
#define RESPONSE_DUMP "log/server.response"
#define MAXDOCNAMELEN 140000
#define MAXDOCNAMELEN_TXT "139999"
#define REQUEST_KEYWORD_SIZE 256
#define REQUEST_KEYWORD_SIZE_TXT "255"
#define CMD_AUTH_REQUIRED "auth_required"
#define CMD_IDLE "idle"
#define CMD_STREAM "stream"
#define END_OF_HEADERS "\r\n\r\n"
#define RTP_DATA_SIZE 12
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
#define STREAMTHIS "a string to stream 01234567890\n"
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
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif /* ENABLE_IPV6 */
#ifdef TCP_NODELAY
#endif
