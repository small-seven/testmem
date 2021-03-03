#include <stdio.h>
#include <string.h>
#include "internal/cryptlib.h"
#include "internal/o_dir.h"
#include <openssl/lhash.h>
#include <openssl/conf.h>
#include <openssl/conf_api.h>
#include "conf_def.h"
#include <openssl/buffer.h>
#include <openssl/err.h>
#ifndef OPENSSL_NO_POSIX_IO
# include <sys/stat.h>
# ifdef _WIN32
#  define stat    _stat
#  define strcasecmp _stricmp
# endif
#endif
#ifndef S_ISDIR
# define S_ISDIR(a) (((a) & S_IFMT) == S_IFDIR)
#endif
#define MAX_CONF_VALUE_LENGTH       65536
#define scan_esc(conf,p)        (((IS_EOF((conf),(p)[1]))?((p)+1):((p)+2)))
#ifndef OPENSSL_NO_POSIX_IO
#endif
static int def_destroy(CONF *conf)
{
    if (def_destroy_data(conf)) {
        OPENSSL_free(conf);
        return 1;
    }
    return 0;
}
#ifdef OPENSSL_SYS_VMS
#else
#endif
#define CONFBUFSIZE     512
#ifndef OPENSSL_NO_POSIX_IO
#endif
#ifndef OPENSSL_NO_POSIX_IO
#endif
#ifndef OPENSSL_NO_POSIX_IO
#else
#endif
#ifndef OPENSSL_NO_POSIX_IO
#endif
#ifndef OPENSSL_NO_POSIX_IO
#ifdef OPENSSL_SYS_VMS
#endif
#endif
#ifdef CHARSET_EBCDIC
# if CHAR_BIT > 8
# endif
#endif
