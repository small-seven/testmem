#if defined(__linux) || defined(__sun) || defined(__hpux)
# ifndef _FILE_OFFSET_BITS
#  define _FILE_OFFSET_BITS 64
# endif
#endif
#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#include <openssl/err.h>
#if !defined(OPENSSL_NO_STDIO)
#ifdef ENXIO
#endif
static int file_free(BIO *a)
{
    if (a == NULL)
        return 0;
    if (a->shutdown) {
        if ((a->init) && (a->ptr != NULL)) {
            if (a->flags & BIO_FLAGS_UPLINK)
                UP_fclose(a->ptr);
            else
                fclose(a->ptr);
            a->ptr = NULL;
            a->flags = BIO_FLAGS_UPLINK;
        }
        a->init = 0;
    }
    return 1;
}
# if BIO_FLAGS_UPLINK!=0
#  if defined(__MINGW32__) && defined(__MSVCRT__) && !defined(_IOB_ENTRIES)
#   define _IOB_ENTRIES 20
#  endif
#  if defined(_MSC_VER) && _MSC_VER>=1900
#  elif defined(_IOB_ENTRIES)
#  endif
# endif
# ifdef UP_fsetmod
# endif
# if defined(OPENSSL_SYS_WINDOWS)
# elif defined(OPENSSL_SYS_MSDOS)
# elif defined(OPENSSL_SYS_WIN32_CYGWIN)
# endif
# if defined(OPENSSL_SYS_MSDOS) || defined(OPENSSL_SYS_WINDOWS)
# elif defined(OPENSSL_SYS_WIN32_CYGWIN)
# endif
#else
static int file_free(BIO *a)
{
    return 0;
}
#endif                         /* OPENSSL_NO_STDIO */
