#include "curl_setup.h"
#ifndef CURL_DISABLE_TELNET
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifdef HAVE_NET_IF_H
#include <net/if.h>
#endif
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#include "urldata.h"
#include <curl/curl.h>
#include "transfer.h"
#include "sendf.h"
#include "telnet.h"
#include "connect.h"
#include "progress.h"
#include "system_win32.h"
#include "arpa_telnet.h"
#include "select.h"
#include "strcase.h"
#include "warnless.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define SUBBUFSIZE 512
#define CURL_SB_CLEAR(x)  x->subpointer = x->subbuffer
#define CURL_SB_TERM(x)                                 \
#define CURL_SB_ACCUM(x,c)                                      \
#define  CURL_SB_GET(x) ((*x->subpointer++)&0xff)
#define  CURL_SB_LEN(x) (x->subend - x->subpointer)
#define  CURL_SB_PEEK(x) ((*x->subpointer)&0xff)
#define  CURL_SB_EOF(x) (x->subpointer >= x->subend) */
#ifdef CURL_DISABLE_VERBOSE_STRINGS
#define printoption(a,b,c,d)  Curl_nop_stmt
#endif
#ifdef USE_WINSOCK
typedef WSAEVENT (WINAPI *WSOCK2_EVENT)(void);
typedef FARPROC WSOCK2_FUNC;
static CURLcode check_wsock2(struct Curl_easy *data);
#endif

static
CURLcode telrcv(struct connectdata *,
                const unsigned char *inbuf, /* Data received from socket */
                ssize_t count);             /* Number of bytes received */

#ifndef CURL_DISABLE_VERBOSE_STRINGS
static void printoption(struct Curl_easy *data,
                        const char *direction,
                        int cmd, int option);
#endif

static void negotiate(struct connectdata *);
static void send_negotiation(struct connectdata *, int cmd, int option);
static void set_local_option(struct connectdata *conn,
                             int option, int newstate);
static void set_remote_option(struct connectdata *conn,
                              int option, int newstate);

static void printsub(struct Curl_easy *data,
                     int direction, unsigned char *pointer,
                     size_t length);
static void suboption(struct connectdata *);
static void sendsuboption(struct connectdata *conn, int option);

static CURLcode telnet_do(struct connectdata *conn, bool *done);
static CURLcode telnet_done(struct connectdata *conn,
                                 CURLcode, bool premature);
static CURLcode send_telnet_data(struct connectdata *conn,
                                 char *buffer, ssize_t nread);

/* For negotiation compliant to RFC 1143 */
#define CURL_NO          0
#define CURL_YES         1
#define CURL_WANTYES     2
#define CURL_WANTNO      3

#define CURL_EMPTY       0
#define CURL_OPPOSITE    1

/*
 * Telnet receiver states for fsm
 */
typedef enum
{
   CURL_TS_DATA = 0,
   CURL_TS_IAC,
   CURL_TS_WILL,
   CURL_TS_WONT,
   CURL_TS_DO,
   CURL_TS_DONT,
   CURL_TS_CR,
   CURL_TS_SB,   /* sub-option collection */
   CURL_TS_SE   /* looking for sub-option end */
} TelnetReceive;
#ifdef USE_WINSOCK
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#define startskipping()                                       \
#define writebyte() \
#define bufferflush() startskipping()
#ifdef USE_WINSOCK
#else
#endif
#ifdef USE_WINSOCK
#else
#endif
#endif
