#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#ifndef OPENSSL_NO_DGRAM
# ifndef OPENSSL_NO_SCTP
#  include <netinet/sctp.h>
#  include <fcntl.h>
#  define OPENSSL_SCTP_DATA_CHUNK_TYPE            0x00
#  define OPENSSL_SCTP_FORWARD_CUM_TSN_CHUNK_TYPE 0xc0
# endif
# if defined(OPENSSL_SYS_LINUX) && !defined(IP_MTU)
#  define IP_MTU      14        /* linux is lame */
# endif
# if OPENSSL_USE_IPV6 && !defined(IPPROTO_IPV6)
#  define IPPROTO_IPV6 41       /* windows is lame */
# endif
# if defined(__FreeBSD__) && defined(IN6_IS_ADDR_V4MAPPED)
#  undef IN6_IS_ADDR_V4MAPPED
#  define s6_addr32 __u6_addr.__u6_addr32
#  define IN6_IS_ADDR_V4MAPPED(a)               \
# endif
# ifndef OPENSSL_NO_SCTP
#  ifdef SCTP_AUTHENTICATION_EVENT
#  endif
# endif
# ifndef OPENSSL_NO_SCTP
# endif
typedef struct bio_dgram_data_st {
    BIO_ADDR peer;
    unsigned int connected;
    unsigned int _errno;
    unsigned int mtu;
    struct timeval next_timeout;
    struct timeval socket_timeout;
    unsigned int peekmode;
} bio_dgram_data;
# ifndef OPENSSL_NO_SCTP
typedef struct bio_dgram_sctp_save_message_st {
    BIO *bio;
    char *data;
    int length;
} bio_dgram_sctp_save_message;
typedef struct bio_dgram_sctp_data_st {
    BIO_ADDR peer;
    unsigned int connected;
    unsigned int _errno;
    unsigned int mtu;
    struct bio_dgram_sctp_sndinfo sndinfo;
    struct bio_dgram_sctp_rcvinfo rcvinfo;
    struct bio_dgram_sctp_prinfo prinfo;
    void (*handle_notifications) (BIO *bio, void *context, void *buf);
    void *notification_context;
    int in_handshake;
    int ccs_rcvd;
    int ccs_sent;
    int save_shutdown;
    int peer_auth_tested;
} bio_dgram_sctp_data;
# endif
static int dgram_free(BIO *a)
{
    bio_dgram_data *data;

    if (a == NULL)
        return 0;
    if (!dgram_clear(a))
        return 0;

    data = (bio_dgram_data *)a->ptr;
    OPENSSL_free(data);

    return 1;
}
# if defined(SO_RCVTIMEO)
#  ifdef OPENSSL_SYS_WINDOWS
#  else
#  endif
#  ifdef OPENSSL_SYS_WINDOWS
#  else
#  endif
# endif
# if defined(SO_RCVTIMEO)
#  ifdef OPENSSL_SYS_WINDOWS
#  else
#  endif
# endif
# if OPENSSL_USE_IPV6
#  ifdef IN6_IS_ADDR_V4MAPPED
#  endif
# endif
# if defined(OPENSSL_SYS_LINUX) && (defined(IP_MTU_DISCOVER) || defined(IP_MTU))
# endif
# if defined(OPENSSL_SYS_LINUX) && defined(IP_MTU_DISCOVER) && defined(IP_PMTUDISC_DO)
#  if OPENSSL_USE_IPV6 && defined(IPV6_MTU_DISCOVER) && defined(IPV6_PMTUDISC_DO)
#  endif
# else
# endif
# if defined(OPENSSL_SYS_LINUX) && defined(IP_MTU)
#  if OPENSSL_USE_IPV6 && defined(IPV6_MTU)
#  endif
# else
# endif
# if OPENSSL_USE_IPV6
#  ifdef IN6_IS_ADDR_V4MAPPED
#  endif
# endif
# if defined(SO_RCVTIMEO)
#  ifdef OPENSSL_SYS_WINDOWS
#  else
#  endif
#  ifdef OPENSSL_SYS_WINDOWS
#  else
#  endif
# endif
# if defined(SO_SNDTIMEO)
#  ifdef OPENSSL_SYS_WINDOWS
#  else
#  endif
#  ifdef OPENSSL_SYS_WINDOWS
#  else
#  endif
# endif
# ifdef OPENSSL_SYS_WINDOWS
# else
# endif
# ifdef EMSGSIZE
# endif
# if defined(IP_DONTFRAG)
# elif defined(OPENSSL_SYS_LINUX) && defined(IP_MTU_DISCOVER) && defined (IP_PMTUDISC_PROBE)
# elif defined(OPENSSL_SYS_WINDOWS) && defined(IP_DONTFRAGMENT)
# else
# endif
# if OPENSSL_USE_IPV6
#  if defined(IPV6_DONTFRAG)
#  elif defined(OPENSSL_SYS_LINUX) && defined(IPV6_MTUDISCOVER)
#  else
#  endif
# endif
# ifndef OPENSSL_NO_SCTP
#  ifdef SCTP_AUTHENTICATION_EVENT
#   ifdef SCTP_EVENT
#   else
#   endif
#  endif
#  ifdef SCTP_AUTHENTICATION_EVENT
#   ifdef SCTP_EVENT
#   else
#   endif
#  endif
#  ifdef SCTP_PR_SCTP_NONE
#  endif
static int dgram_sctp_free(BIO *a)
{
    bio_dgram_sctp_data *data;

    if (a == NULL)
        return 0;
    if (!dgram_clear(a))
        return 0;

    data = (bio_dgram_sctp_data *) a->ptr;
    if (data != NULL)
        OPENSSL_free(data);

    return 1;
}
#  ifdef SCTP_AUTHENTICATION_EVENT
#  endif
#  ifdef SCTP_RCVINFO
#  endif
#  ifdef SCTP_SNDRCV
#  endif
#  ifdef SCTP_EVENT
#  else
#  endif
#  ifdef SCTP_EVENT
#  else
#  endif
#  ifdef SCTP_AUTHENTICATION_EVENT
#  endif
#  if defined(SCTP_SNDINFO) && defined(SCTP_PRINFO)
#  else
#  endif
#  ifdef SCTP_SACK_IMMEDIATELY
#  endif
#  if defined(SCTP_SNDINFO) && defined(SCTP_PRINFO)
#  else
#   ifdef __FreeBSD__
#   endif
#  endif
#  ifndef __FreeBSD__
#  endif
#  ifdef SCTP_AUTH_DEACTIVATE_KEY
#  endif
#  ifndef SCTP_AUTHENTICATION_EVENT
#  endif
#  ifdef SCTP_EVENT
#  else
#  endif
#  ifdef SCTP_EVENT
#  else
#  endif
#  ifdef SCTP_EVENT
#  else
#  endif
#  ifdef SCTP_AUTHENTICATION_EVENT
#  endif
#  ifdef SCTP_AUTHENTICATION_EVENT
#  endif
# endif
# if defined(OPENSSL_SYS_WINDOWS)
# endif
# if defined(OPENSSL_SYS_WINDOWS)
#  if defined(WSAEWOULDBLOCK)
#  endif
# endif
# ifdef EWOULDBLOCK
#  ifdef WSAEWOULDBLOCK
#   if WSAEWOULDBLOCK != EWOULDBLOCK
#   endif
#  else
#  endif
# endif
# ifdef EINTR
# endif
# ifdef EAGAIN
#  if EWOULDBLOCK != EAGAIN
#  endif
# endif
# ifdef EPROTO
# endif
# ifdef EINPROGRESS
# endif
# ifdef EALREADY
# endif
# if defined(_WIN32)
#  ifdef  __MINGW32__
#  else
#  endif
# else
# endif
#endif
