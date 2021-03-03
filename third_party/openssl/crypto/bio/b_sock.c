#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "bio_local.h"
#ifndef OPENSSL_NO_SOCK
# define SOCKET_PROTOCOL IPPROTO_TCP
# ifdef SO_MAXCONN
#  define MAX_LISTEN  SO_MAXCONN
# elif defined(SOMAXCONN)
#  define MAX_LISTEN  SOMAXCONN
# else
#  define MAX_LISTEN  32
# endif
# if defined(OPENSSL_SYS_WINDOWS)
# endif
# if OPENSSL_API_COMPAT < 0x10100000L
# endif
# if OPENSSL_API_COMPAT < 0x10100000L
# endif
# ifdef OPENSSL_SYS_WINDOWS
# endif                         /* OPENSSL_SYS_WINDOWS */
# ifdef WATT32
# endif
# ifdef OPENSSL_SYS_WINDOWS
# endif
#  ifdef __DJGPP__
#  else
#   if defined(OPENSSL_SYS_VMS)
#    if __INITIAL_POINTER_SIZE == 64
#     define ARG arg_32p
#     pragma pointer_size save
#     pragma pointer_size 32
#     pragma pointer_size restore
#    else                       /* __INITIAL_POINTER_SIZE == 64 */
#     define ARG arg
#    endif                      /* __INITIAL_POINTER_SIZE == 64 [else] */
#   else                        /* defined(OPENSSL_SYS_VMS) */
#    define ARG arg
#   endif                       /* defined(OPENSSL_SYS_VMS) [else] */
#  endif                        /* __DJGPP__ */
# if OPENSSL_API_COMPAT < 0x10100000L
# endif
# if defined(TCP_NODELAY) && (defined(IPPROTO_TCP) || defined(SOL_TCP))
#  ifdef SOL_TCP
#  else
#   ifdef IPPROTO_TCP
#   endif
#  endif
# endif
# ifdef FIONBIO
# elif defined(F_GETFL) && defined(F_SETFL) && (defined(O_NONBLOCK) || defined(FNDELAY))
#  if defined(O_NONBLOCK)
#  else
#  endif
#  if defined(O_NONBLOCK)
#  else
#  endif
# else
# endif
#endif
