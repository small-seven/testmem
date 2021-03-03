#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "crypto/cryptlib.h"
#include "internal/err.h"
#include "crypto/err.h"
#include <openssl/err.h>
#include <openssl/crypto.h>
#include <openssl/buffer.h>
#include <openssl/bio.h>
#include <openssl/opensslconf.h>
#include "internal/thread_once.h"
#include "crypto/ctype.h"
#include "internal/constant_time.h"
#include "e_os.h"
#ifndef OPENSSL_NO_ERR
# ifdef OPENSSL_SYS_WINDOWS
# endif
#endif
#ifndef OPENSSL_NO_ERR
# define SPACE_SYS_STR_REASONS 8 * 1024
# define NUM_SYS_STR_REASONS 127
#endif
#define err_clear_data(p, i) \
#define err_clear(p, i) \
static void ERR_STATE_free(ERR_STATE *s)
{
    int i;

    if (s == NULL)
        return;
    for (i = 0; i < ERR_NUM_ERRORS; i++) {
        err_clear_data(s, i);
    }
    OPENSSL_free(s);
}
#ifndef OPENSSL_NO_ERR
#endif
#ifdef _OSD_POSIX
#endif
#if OPENSSL_API_COMPAT < 0x10100000L
#endif
#if OPENSSL_API_COMPAT < 0x10000000L
#endif
