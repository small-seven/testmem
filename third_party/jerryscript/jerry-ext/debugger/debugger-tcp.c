#include "jerryscript-debugger-transport.h"
#include "jerryscript-ext/debugger.h"
#include "jext-common.h"
#if defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)
#include <errno.h>
#ifdef _WIN32
#include <basetsd.h>
typedef SSIZE_T ssize_t;
#include <ws2tcpip.h>
#include <winsock2.h>

/* On Windows the WSAEWOULDBLOCK value can be returned for non-blocking operations */
#define JERRYX_EWOULDBLOCK WSAEWOULDBLOCK

/* On Windows the invalid socket's value of INVALID_SOCKET */
#define JERRYX_SOCKET_INVALID INVALID_SOCKET

/* On Windows sockets have a SOCKET typedef */
typedef SOCKET jerryx_socket;

#else /* !_WIN32 */

#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <unistd.h>

/* On *nix the EWOULDBLOCK errno value can be returned for non-blocking operations */
#define JERRYX_EWOULDBLOCK EWOULDBLOCK

/* On *nix the invalid socket has a value of -1 */
#define JERRYX_SOCKET_INVALID (-1)

/* On *nix the sockets are integer identifiers */
typedef int jerryx_socket;
#endif /* _WIN32 */

/**
 * Implementation of transport over tcp/ip.
 */
typedef struct
{
  jerry_debugger_transport_header_t header; /**< transport header */
  jerryx_socket tcp_socket; /**< tcp socket */
} jerryx_debugger_transport_tcp_t;
#ifdef _WIN32
#else /* !_WIN32 */
#endif /* _WIN32 */
#ifdef _WIN32
#else /* !_WIN32 */
#endif /* _WIN32 */
#ifdef _WIN32
#else /* !_WIN32 */
#endif /* _WIN32 */
#ifdef __linux__
#endif /* __linux__ */
#ifdef _WIN32
#else
#endif
#ifdef _WIN32
#else
#endif
#ifdef _WIN32
#else
#endif
#ifdef _WIN32
#endif /* _WIN32 */
#ifdef _WIN32
#else /* !_WIN32 */
#endif /* _WIN32 */
#else /* !(defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)) */
#endif /* defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1) */
