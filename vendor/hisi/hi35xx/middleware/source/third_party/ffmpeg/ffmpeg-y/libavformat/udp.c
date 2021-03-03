#define _DEFAULT_SOURCE
#define _BSD_SOURCE     /* Needed for using struct ip_mreq with recent glibc */
#include "avformat.h"
#include "avio_internal.h"
#include "libavutil/avassert.h"
#include "libavutil/parseutils.h"
#include "libavutil/fifo.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "libavutil/log.h"
#include "libavutil/time.h"
#include "internal.h"
#include "network.h"
#include "os_support.h"
#include "url.h"
#include "ip.h"
#ifdef __APPLE__
#include "TargetConditionals.h"
#endif
#if HAVE_UDPLITE_H
#include "udplite.h"
#else
#define UDPLITE_SEND_CSCOV                               10
#define UDPLITE_RECV_CSCOV                               11
#endif
#ifndef IPPROTO_UDPLITE
#define IPPROTO_UDPLITE                                  136
#endif
#if HAVE_PTHREAD_CANCEL
#include <pthread.h>
#endif
#ifndef IPV6_ADD_MEMBERSHIP
#define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
#define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
#endif
#define UDP_TX_BUF_SIZE 32768
#define UDP_MAX_PKT_SIZE 65536
#define UDP_HEADER_SIZE 8
typedef struct UDPContext {
    const AVClass *class;
    int udp_fd;
    int ttl;
    int udplite_coverage;
    int buffer_size;
    int pkt_size;
    int is_multicast;
    int is_broadcast;
    int local_port;
    int reuse_socket;
    int overrun_nonfatal;
    struct sockaddr_storage dest_addr;
    int dest_addr_len;
    int is_connected;

    /* Circular Buffer variables for use in UDP receive code */
    int circular_buffer_size;
    AVFifoBuffer *fifo;
    int circular_buffer_error;
    int64_t bitrate; /* number of bits to send per second */
    int64_t burst_bits;
    int close_req;
#if HAVE_PTHREAD_CANCEL
    pthread_t circular_buffer_thread;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int thread_started;
#endif
    uint8_t tmp[UDP_MAX_PKT_SIZE+4];
    int remaining_in_dg;
    char *localaddr;
    int timeout;
    struct sockaddr_storage local_addr_storage;
    char *sources;
    char *block;
    IPSourceFilters filters;
} UDPContext;
#define OFFSET(x) offsetof(UDPContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM
#ifdef IP_MULTICAST_TTL
#endif
#if defined(IPPROTO_IPV6) && defined(IPV6_MULTICAST_HOPS)
#endif
#ifdef IP_ADD_MEMBERSHIP
#endif
#if HAVE_STRUCT_IPV6_MREQ && defined(IPPROTO_IPV6)
#endif
#ifdef IP_DROP_MEMBERSHIP
#endif
#if HAVE_STRUCT_IPV6_MREQ && defined(IPPROTO_IPV6)
#endif
#if HAVE_STRUCT_GROUP_SOURCE_REQ && defined(MCAST_BLOCK_SOURCE)
#else
#endif
#if HAVE_STRUCT_IP_MREQ_SOURCE && defined(IP_BLOCK_SOURCE)
#else
#endif
#if HAVE_PTHREAD_CANCEL
#endif
#ifdef SO_BROADCAST
#endif
#if HAVE_PTHREAD_CANCEL
#endif
#if HAVE_PTHREAD_CANCEL
#endif
#if HAVE_PTHREAD_CANCEL
#endif
#if HAVE_PTHREAD_CANCEL
#endif
#if HAVE_PTHREAD_CANCEL
#endif
#if HAVE_PTHREAD_CANCEL
#endif
