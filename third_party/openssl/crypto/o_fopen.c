# if defined(__linux) || defined(__sun) || defined(__hpux)
#  ifndef _FILE_OFFSET_BITS
#   define _FILE_OFFSET_BITS 64
#  endif
# endif
#include "e_os.h"
#include "internal/cryptlib.h"
#if !defined(OPENSSL_NO_STDIO)
# include <stdio.h>
# ifdef __DJGPP__
#  include <unistd.h>
# endif
# if defined(_WIN32) && defined(CP_UTF8)
# elif defined(__DJGPP__)
# else
# endif
#else
#endif
