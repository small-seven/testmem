#include "curl_setup.h"
#ifndef CURL_DISABLE_TFTP
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
#include "tftp.h"
#include "progress.h"
#include "connect.h"
#include "strerror.h"
#include "sockaddr.h" /* required for Curl_sockaddr_storage */
#include "multiif.h"
#include "url.h"
#include "strcase.h"
#include "speedcheck.h"
#include "select.h"
#include "escape.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#define TFTP_BLKSIZE_DEFAULT 512
#define TFTP_BLKSIZE_MIN 8
#define TFTP_BLKSIZE_MAX 65464
#define TFTP_OPTION_BLKSIZE "blksize"
#define TFTP_OPTION_TSIZE    "tsize"
#define TFTP_OPTION_INTERVAL "timeout"
typedef enum {
  TFTP_MODE_NETASCII = 0,
  TFTP_MODE_OCTET
} tftp_mode_t;
typedef enum {
  TFTP_STATE_START = 0,
  TFTP_STATE_RX,
  TFTP_STATE_TX,
  TFTP_STATE_FIN
} tftp_state_t;
typedef enum {
  TFTP_EVENT_NONE = -1,
  TFTP_EVENT_INIT = 0,
  TFTP_EVENT_RRQ = 1,
  TFTP_EVENT_WRQ = 2,
  TFTP_EVENT_DATA = 3,
  TFTP_EVENT_ACK = 4,
  TFTP_EVENT_ERROR = 5,
  TFTP_EVENT_OACK = 6,
  TFTP_EVENT_TIMEOUT
} tftp_event_t;
typedef enum {
  TFTP_ERR_UNDEF = 0,
  TFTP_ERR_NOTFOUND,
  TFTP_ERR_PERM,
  TFTP_ERR_DISKFULL,
  TFTP_ERR_ILLEGAL,
  TFTP_ERR_UNKNOWNID,
  TFTP_ERR_EXISTS,
  TFTP_ERR_NOSUCHUSER,  /* This will never be triggered by this code */

  /* The remaining error codes are internal to curl */
  TFTP_ERR_NONE = -100,
  TFTP_ERR_TIMEOUT,
  TFTP_ERR_NORESPONSE
} tftp_error_t;
typedef struct tftp_packet {
  unsigned char *data;
} tftp_packet_t;
typedef struct tftp_state_data {
  tftp_state_t    state;
  tftp_mode_t     mode;
  tftp_error_t    error;
  tftp_event_t    event;
  struct connectdata      *conn;
  curl_socket_t   sockfd;
  int             retries;
  int             retry_time;
  int             retry_max;
  time_t          start_time;
  time_t          max_time;
  time_t          rx_time;
  unsigned short  block;
  struct Curl_sockaddr_storage   local_addr;
  struct Curl_sockaddr_storage   remote_addr;
  curl_socklen_t  remote_addrlen;
  int             rbytes;
  int             sbytes;
  int             blksize;
  int             requested_blksize;
  tftp_packet_t   rpacket;
  tftp_packet_t   spacket;
} tftp_state_data_t;
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#ifndef CURL_DISABLE_VERBOSE_STRINGS
#endif
#define NEXT_BLOCKNUM(x) (((x) + 1)&0xffff)
#endif
