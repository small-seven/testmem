#include "server_setup.h"
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef HAVE_ARPA_TFTP_H
#include <arpa/tftp.h>
#else
#include "tftp.h"
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef HAVE_SYS_FILIO_H
#include <sys/filio.h>
#endif
#include <setjmp.h>
#ifdef HAVE_PWD_H
#include <pwd.h>
#endif
#define ENABLE_CURLX_PRINTF
#include "curlx.h" /* from the private lib dir */
#include "getpart.h"
#include "util.h"
#include "server_sockaddr.h"
#include "memdebug.h"
#ifndef PKTSIZE
#define PKTSIZE (SEGSIZE + 4)  /* SEGSIZE defined in arpa/tftp.h */
#endif
typedef union {
  struct tftphdr hdr;
  char storage[PKTSIZE];
} tftphdr_storage_t;
#define BF_ALLOC -3       /* alloc'd but not yet filled */
#define BF_FREE  -2       /* free */
#define opcode_RRQ   1
#define opcode_WRQ   2
#define opcode_DATA  3
#define opcode_ACK   4
#define opcode_ERROR 5
#define TIMEOUT      5
#undef MIN
#define MIN(x,y) ((x)<(y)?(x):(y))
#ifndef DEFAULT_LOGFILE
#define DEFAULT_LOGFILE "log/tftpd.log"
#endif
#define REQUEST_DUMP  "log/server.input"
#define DEFAULT_PORT 8999 /* UDP */
#ifdef ENABLE_IPV6
#endif
#ifdef HAVE_SIGSETJMP
#endif
#if defined(HAVE_ALARM) && defined(SIGALRM)
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

/*****************************************************************************
*                            FUNCTION PROTOTYPES                             *
*****************************************************************************/

static struct tftphdr *rw_init(int);

static struct tftphdr *w_init(void);

static struct tftphdr *r_init(void);

static void read_ahead(struct testcase *test, int convert);

static ssize_t write_behind(struct testcase *test, int convert);

static int synchnet(curl_socket_t);

static int do_tftp(struct testcase *test, struct tftphdr *tp, ssize_t size);

static int validate_access(struct testcase *test, const char *fname, int mode);

static void sendtftp(struct testcase *test, struct formats *pf);

static void recvtftp(struct testcase *test, struct formats *pf);

static void nak(int error);

#if defined(HAVE_ALARM) && defined(SIGALRM)

static void mysignal(int sig, void (*handler)(int));

static void timer(int signum);

static void justtimeout(int signum);

#endif /* HAVE_ALARM && SIGALRM */

static RETSIGTYPE exit_signal_handler(int signum);

static void install_signal_handlers(void);

static void restore_signal_handlers(void);

/*****************************************************************************
*                          FUNCTION IMPLEMENTATIONS                          *
*****************************************************************************/

#if defined(HAVE_ALARM) && defined(SIGALRM)

/*
 * Like signal(), but with well-defined semantics.
 */
static void mysignal(int sig, void (*handler)(int))
{
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = handler;
  sigaction(sig, &sa, NULL);
}
#ifdef HAVE_SIGSETJMP
#endif
#endif /* HAVE_ALARM && SIGALRM */
#ifdef SIGHUP
#endif
#ifdef SIGPIPE
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
#ifdef SIGINT
#endif
#ifdef SIGTERM
#endif
#if defined(SIGBREAK) && defined(WIN32)
#endif
#ifdef WIN32
#else
#endif
#if defined(HAVE_IOCTLSOCKET)
#else
#endif
#if defined(HAVE_IOCTLSOCKET)
#else
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
#endif
#ifdef USE_WINSOCK
#endif
#ifdef USE_WINSOCK
#endif
#ifdef USE_WINSOCK
#endif
#if defined(HAVE_ALARM) && defined(SIGALRM)
#endif
#ifdef HAVE_SIGSETJMP
#endif
#ifdef HAVE_ALARM
#endif
#ifdef HAVE_ALARM
#endif
#if defined(HAVE_ALARM) && defined(SIGALRM)
#endif
#ifdef HAVE_SIGSETJMP
#endif
#ifdef HAVE_ALARM
#endif
#ifdef HAVE_ALARM
#endif
#if defined(HAVE_ALARM) && defined(SIGALRM)
#endif
#ifdef HAVE_ALARM
#endif
