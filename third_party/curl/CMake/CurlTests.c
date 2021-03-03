#ifdef TIME_WITH_SYS_TIME
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#endif
#ifdef HAVE_FCNTL_O_NONBLOCK
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#if defined(sun) || defined(__sun__) || \
# if defined(__SVR4) || defined(__srv4__)
#  define PLATFORM_SOLARIS
# else
#  define PLATFORM_SUNOS4
# endif
#endif
#if (defined(_AIX) || defined(__xlC__)) && !defined(_AIX41)
# define PLATFORM_AIX_V3
#endif
#if defined(PLATFORM_SUNOS4) || defined(PLATFORM_AIX_V3) || defined(__BEOS__)
#error "O_NONBLOCK does not work on this platform"
#endif
#endif
#if defined(HAVE_GETHOSTBYADDR_R_5_REENTRANT) || \
#   define _REENTRANT
#   define TEST_GETHOSTBYFOO_REENTRANT
#endif
#if defined(HAVE_GETHOSTBYADDR_R_5) || \
#include <sys/types.h>
#include <netdb.h>
#if defined(HAVE_GETHOSTBYADDR_R_5) || \
#elif defined(HAVE_GETHOSTBYADDR_R_7) || \
#endif
#ifndef gethostbyaddr_r
#endif
#if   defined(HAVE_GETHOSTBYADDR_R_5) || \
#elif defined(HAVE_GETHOSTBYADDR_R_7) || \
#elif defined(HAVE_GETHOSTBYADDR_R_8) || \
#endif
#if   defined(HAVE_GETHOSTBYNAME_R_3) || \
#elif defined(HAVE_GETHOSTBYNAME_R_5) || \
#elif defined(HAVE_GETHOSTBYNAME_R_6) || \
#endif
#endif
#ifdef HAVE_SOCKLEN_T
#ifdef _WIN32
#include <ws2tcpip.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#endif
#endif
#ifdef HAVE_IN_ADDR_T
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#endif
#ifdef HAVE_BOOL_T
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_STDBOOL_H
#include <stdbool.h>
#endif
#endif
#ifdef STDC_HEADERS
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <float.h>
#endif
#ifdef RETSIGTYPE_TEST
#include <sys/types.h>
#include <signal.h>
#ifdef signal
# undef signal
#endif
#ifdef __cplusplus
#else
#endif
#endif
#ifdef HAVE_INET_NTOA_R_DECL
#include <arpa/inet.h>
typedef void (*func_type)();

int main()
{
#ifndef inet_ntoa_r
  func_type func;
  func = (func_type)inet_ntoa_r;
  (void)func;
#endif
  return 0;
}
#endif
#ifdef HAVE_INET_NTOA_R_DECL_REENTRANT
#define _REENTRANT
#include <arpa/inet.h>
typedef void (*func_type)();

int main()
{
#ifndef inet_ntoa_r
  func_type func;
  func = (func_type)&inet_ntoa_r;
  (void)func;
#endif
  return 0;
}
#endif
#ifdef HAVE_GETADDRINFO
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#ifndef getaddrinfo
#endif
#endif
#ifdef HAVE_FILE_OFFSET_BITS
#ifdef _FILE_OFFSET_BITS
#undef _FILE_OFFSET_BITS
#endif
#define _FILE_OFFSET_BITS 64
#include <sys/types.h>
#define LARGE_OFF_T (((off_t) 1 << 62) - 1 + ((off_t) 1 << 62))
#endif
#ifdef HAVE_IOCTLSOCKET
#ifdef HAVE_WINDOWS_H
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#  include <windows.h>
#  ifdef HAVE_WINSOCK2_H
#    include <winsock2.h>
#  else
#    ifdef HAVE_WINSOCK_H
#      include <winsock.h>
#    endif
#  endif
#endif
#endif
#ifdef HAVE_IOCTLSOCKET_CAMEL
#ifdef HAVE_WINDOWS_H
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#  include <windows.h>
#  ifdef HAVE_WINSOCK2_H
#    include <winsock2.h>
#  else
#    ifdef HAVE_WINSOCK_H
#      include <winsock.h>
#    endif
#  endif
#endif
#endif
#ifdef HAVE_IOCTLSOCKET_CAMEL_FIONBIO
#ifdef HAVE_WINDOWS_H
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#  include <windows.h>
#  ifdef HAVE_WINSOCK2_H
#    include <winsock2.h>
#  else
#    ifdef HAVE_WINSOCK_H
#      include <winsock.h>
#    endif
#  endif
#endif
#endif
#ifdef HAVE_IOCTLSOCKET_FIONBIO
#ifdef HAVE_WINDOWS_H
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#  include <windows.h>
#  ifdef HAVE_WINSOCK2_H
#    include <winsock2.h>
#  else
#    ifdef HAVE_WINSOCK_H
#      include <winsock.h>
#    endif
#  endif
#endif
#endif
#ifdef HAVE_IOCTL_FIONBIO
#ifdef HAVE_SYS_TYPES_H
#  include <sys/types.h>
#endif
#ifdef HAVE_UNISTD_H
#  include <unistd.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
#  include <sys/socket.h>
#endif
#ifdef HAVE_SYS_IOCTL_H
#  include <sys/ioctl.h>
#endif
#ifdef HAVE_STROPTS_H
#  include <stropts.h>
#endif
#endif
#ifdef HAVE_IOCTL_SIOCGIFADDR
#ifdef HAVE_SYS_TYPES_H
#  include <sys/types.h>
#endif
#ifdef HAVE_UNISTD_H
#  include <unistd.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
#  include <sys/socket.h>
#endif
#ifdef HAVE_SYS_IOCTL_H
#  include <sys/ioctl.h>
#endif
#ifdef HAVE_STROPTS_H
#  include <stropts.h>
#endif
#include <net/if.h>
#endif
#ifdef HAVE_SETSOCKOPT_SO_NONBLOCK
#ifdef HAVE_WINDOWS_H
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#  include <windows.h>
#  ifdef HAVE_WINSOCK2_H
#    include <winsock2.h>
#  else
#    ifdef HAVE_WINSOCK_H
#      include <winsock.h>
#    endif
#  endif
#endif
#ifdef HAVE_SYS_TYPES_H
#  include <sys/types.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
#  include <sys/socket.h>
#endif
#endif
#ifdef HAVE_GLIBC_STRERROR_R
#include <string.h>
#include <errno.h>
#endif
#ifdef HAVE_POSIX_STRERROR_R
#include <string.h>
#include <errno.h>
#endif
#ifdef HAVE_FSETXATTR_6
#include <sys/xattr.h> /* header from libc, not from libattr */
#endif
#ifdef HAVE_FSETXATTR_5
#include <sys/xattr.h> /* header from libc, not from libattr */
#endif
#ifdef HAVE_CLOCK_GETTIME_MONOTONIC
#include <time.h>
#endif
#ifdef HAVE_BUILTIN_AVAILABLE
#endif
#ifdef HAVE_VARIADIC_MACROS_C99
#define c99_vmacro3(first, ...) fun3(first, __VA_ARGS__)
#define c99_vmacro2(first, ...) fun2(first, __VA_ARGS__)
#endif
#ifdef HAVE_VARIADIC_MACROS_GCC
#define gcc_vmacro3(first, args...) fun3(first, args)
#define gcc_vmacro2(first, args...) fun2(first, args)
#endif
