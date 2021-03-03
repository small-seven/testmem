#include <stdlib.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include "testutil.h"
#ifdef _WIN32
# include <direct.h>
# define DIRSEP "/\\"
# define chdir _chdir
# define DIRSEP_PRESERVE 0
#elif !defined(OPENSSL_NO_POSIX_IO)
# include <unistd.h>
# ifndef OPENSSL_SYS_VMS
#  define DIRSEP "/"
#  define DIRSEP_PRESERVE 0
# else
#  define DIRSEP "/]:"
#  define DIRSEP_PRESERVE 1
# endif
#else
# define chdir(x) (-1);
# define DIRSEP "/"
#  define DIRSEP_PRESERVE 0
#endif
#if defined(_BSD_SOURCE) \
#endif
#if defined(_BSD_SOURCE) \
#endif
