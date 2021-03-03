#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "bio_local.h"
#include <openssl/err.h>
#ifndef OPENSSL_NO_SOCK
# ifdef SO_MAXCONN
#  define MAX_LISTEN  SO_MAXCONN
# elif defined(SOMAXCONN)
#  define MAX_LISTEN  SOMAXCONN
# else
#  define MAX_LISTEN  32
# endif
# ifndef OPENSSL_SYS_WINDOWS
# endif
# ifndef OPENSSL_SYS_WINDOWS
# endif
# ifdef IPV6_V6ONLY
# endif
#endif
