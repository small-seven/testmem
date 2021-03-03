#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define mbedtls_time            time
#define mbedtls_time_t          time_t
#define mbedtls_printf          printf
#define mbedtls_calloc          calloc
#define mbedtls_free            free
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */
#if !defined(MBEDTLS_NET_C)
#else
#include "mbedtls/net_sockets.h"
#include "mbedtls/error.h"
#include "mbedtls/ssl.h"
#include "mbedtls/timing.h"
#include <string.h>
#if (defined(_WIN32) || defined(_WIN32_WCE)) && !defined(EFIX64) && \
#include <winsock2.h>
#include <windows.h>
#if defined(_MSC_VER)
#if defined(_WIN32_WCE)
#pragma comment( lib, "ws2.lib" )
#else
#pragma comment( lib, "ws2_32.lib" )
#endif
#endif /* _MSC_VER */
#else /* ( _WIN32 || _WIN32_WCE ) && !EFIX64 && !EFI32 */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#endif /* ( _WIN32 || _WIN32_WCE ) && !EFIX64 && !EFI32 */
#define MAX_MSG_SIZE            16384 + 2048 /* max record/datagram size */
#define DFL_SERVER_ADDR         "localhost"
#define DFL_SERVER_PORT         "4433"
#define DFL_LISTEN_ADDR         "localhost"
#define DFL_LISTEN_PORT         "5556"
#define DFL_PACK                0
#if defined(MBEDTLS_TIMING_C)
#define USAGE_PACK                                                          \
#else
#define USAGE_PACK
#endif
#define USAGE                                                               \
#define MAX_DELAYED_HS 10
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_TIMING_C)
typedef struct
{
    mbedtls_net_context *ctx;

    const char *description;

    unsigned packet_lifetime;
    unsigned num_datagrams;

    unsigned char data[MAX_MSG_SIZE];
    size_t len;

} ctx_buffer;
#endif /* MBEDTLS_TIMING_C */
#if defined(MBEDTLS_TIMING_C)
#endif /* MBEDTLS_TIMING_C */
typedef struct
{
    mbedtls_net_context *dst;
    const char *way;
    const char *type;
    unsigned len;
    unsigned char buf[MAX_MSG_SIZE];
} packet;
#if defined(MBEDTLS_TIMING_C)
#else
#endif
typedef enum {
    ICH_INIT,       /* haven't seen the first ClientHello yet */
    ICH_CACHED,     /* cached the initial ClientHello */
    ICH_INJECTED,   /* ClientHello already injected, done */
} inject_clihlo_state_t;
#define MAX_DELAYED_MSG 5
#define DROP_MAX 2
#if defined( MBEDTLS_TIMING_C )
#endif
#if defined(MBEDTLS_TIMING_C)
#endif /* MBEDTLS_TIMING_C */
#if defined(MBEDTLS_TIMING_C)
#endif /* MBEDTLS_TIMING_C */
#ifdef MBEDTLS_ERROR_C
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_NET_C */
