#define _POSIX_C_SOURCE 200112L
#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_NET_C)
#if !defined(unix) && !defined(__unix__) && !defined(__unix) && \
#error "This module only works on Unix and Windows, see MBEDTLS_NET_C in config.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#endif
#include "mbedtls/net_sockets.h"
#include <string.h>
#if (defined(_WIN32) || defined(_WIN32_WCE)) && !defined(EFIX64) && \
#define IS_EINTR( ret ) ( ( ret ) == WSAEINTR )
#if !defined(_WIN32_WINNT) || (_WIN32_WINNT < 0x0501)
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#include <ws2tcpip.h>
#include <winsock2.h>
#include <windows.h>
#if defined(_MSC_VER)
#if defined(_WIN32_WCE)
#pragma comment( lib, "ws2.lib" )
#else
#pragma comment( lib, "ws2_32.lib" )
#endif
#endif /* _MSC_VER */
#define read(fd,buf,len)        recv( fd, (char*)( buf ), (int)( len ), 0 )
#define write(fd,buf,len)       send( fd, (char*)( buf ), (int)( len ), 0 )
#define close(fd)               closesocket(fd)
#else /* ( _WIN32 || _WIN32_WCE ) && !EFIX64 && !EFI32 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <netdb.h>
#include <errno.h>
#define IS_EINTR( ret ) ( ( ret ) == EINTR )
#endif /* ( _WIN32 || _WIN32_WCE ) && !EFIX64 && !EFI32 */
#if defined(_MSC_VER)
#define MSVC_INT_CAST   (int)
#else
#define MSVC_INT_CAST
#endif
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#if ( defined(_WIN32) || defined(_WIN32_WCE) ) && !defined(EFIX64) && \
#else
#if !defined(EFIX64) && !defined(EFI32)
#endif
#endif
#if ( defined(_WIN32) || defined(_WIN32_WCE) ) && !defined(EFIX64) && \
#else
#if defined EAGAIN
#endif
#if defined EWOULDBLOCK && EWOULDBLOCK != EAGAIN
#endif
#endif /* ( _WIN32 || _WIN32_WCE ) && !EFIX64 && !EFI32 */
#if defined(__socklen_t_defined) || defined(_SOCKLEN_T) ||  \
#else
#endif
#if defined(_WIN32)
#endif
#if ( defined(_WIN32) || defined(_WIN32_WCE) ) && !defined(EFIX64) && \
#else
#endif
#if ( defined(_WIN32) || defined(_WIN32_WCE) ) && !defined(EFIX64) && \
#else
#endif
#if defined(__has_feature)
#if __has_feature(memory_sanitizer)
#endif
#endif
#if defined(_WIN32)
#else
#if defined(__unix__) || defined(__unix) || \
#else
#endif
#endif
#if ( defined(_WIN32) || defined(_WIN32_WCE) ) && !defined(EFIX64) && \
#else
#endif
#if ( defined(_WIN32) || defined(_WIN32_WCE) ) && !defined(EFIX64) && \
#else
#endif
#if ( defined(_WIN32) || defined(_WIN32_WCE) ) && !defined(EFIX64) && \
#else
#endif
void mbedtls_net_free( mbedtls_net_context *ctx )
{
    if( ctx->fd == -1 )
        return;

    shutdown( ctx->fd, 2 );
    close( ctx->fd );

    ctx->fd = -1;
}
#endif /* MBEDTLS_NET_C */
