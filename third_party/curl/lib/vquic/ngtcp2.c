#include "curl_setup.h"
#ifdef USE_NGTCP2
#include <ngtcp2/ngtcp2.h>
#include <ngtcp2/ngtcp2_crypto.h>
#include <nghttp3/nghttp3.h>
#include <openssl/err.h>
#include "urldata.h"
#include "sendf.h"
#include "strdup.h"
#include "rand.h"
#include "ngtcp2.h"
#include "multiif.h"
#include "strcase.h"
#include "connect.h"
#include "strerror.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef CURLDEBUG
#define DEBUG_HTTP3
#endif
#ifdef DEBUG_HTTP3
#define H3BUGF(x) x
#else
#define H3BUGF(x) do { } while(0)
#endif
#define H3_SEND_SIZE (20*1024)
#define QUIC_MAX_STREAMS (256*1024)
#define QUIC_MAX_DATA (1*1024*1024)
#define QUIC_IDLE_TIMEOUT 60000 /* milliseconds */
#define QUIC_CIPHERS                                                          \
#define QUIC_GROUPS "P-256:X25519:P-384:P-521"
#ifdef DEBUG_NGTCP2
#endif
#ifdef DEBUG_NGTCP2
#else
#endif
#ifdef NGTCP2_PROTO_VER
#endif
#ifdef NGTCP2_PROTO_VER
#define QUICVER NGTCP2_PROTO_VER
#else
#error "unsupported ngtcp2 version"
#endif
#define OVERFLOWSIZE 1024
#if 0 /* extra debugging of incoming h3 data */
#endif
#if 0 /* extra debugging of incoming h3 data */
#endif
#if 0 /* extra debugging of incoming h3 data */
#endif
#define AUTHORITY_DST_IDX 3
#if 0 /* This should probably go in more or less like this */
#endif
#define MAX_ACC 60000  /* <64KB to account for some overhead */
#ifdef ENABLE_IPV6
#endif
#endif
