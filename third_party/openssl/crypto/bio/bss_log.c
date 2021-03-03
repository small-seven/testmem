#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#include "internal/cryptlib.h"
#if defined(OPENSSL_SYS_WINCE)
#elif defined(OPENSSL_SYS_WIN32)
#elif defined(OPENSSL_SYS_VMS)
# include <opcdef.h>
# include <descrip.h>
# include <lib$routines.h>
# include <starlet.h>
# if __INITIAL_POINTER_SIZE && defined _ANSI_C_SOURCE
#  if __INITIAL_POINTER_SIZE == 64
#   pragma pointer_size save
#   pragma pointer_size 32
#   pragma pointer_size restore
#  endif                        /* __INITIAL_POINTER_SIZE == 64 */
# endif                         /* __INITIAL_POINTER_SIZE && defined
#elif defined(__DJGPP__) && defined(OPENSSL_NO_SOCK)
# define NO_SYSLOG
#elif (!defined(MSDOS) || defined(WATT32)) && !defined(OPENSSL_SYS_VXWORKS) && !defined(NO_SYSLOG)
# include <syslog.h>
#endif
#include <openssl/buffer.h>
#include <openssl/err.h>
#ifndef NO_SYSLOG
# if defined(OPENSSL_SYS_WIN32)
#  define LOG_EMERG       0
#  define LOG_ALERT       1
#  define LOG_CRIT        2
#  define LOG_ERR         3
#  define LOG_WARNING     4
#  define LOG_NOTICE      5
#  define LOG_INFO        6
#  define LOG_DEBUG       7
#  define LOG_DAEMON      (3<<3)
# elif defined(OPENSSL_SYS_VMS)
#  define LOG_EMERG       0
#  define LOG_ALERT       1
#  define LOG_CRIT        2
#  define LOG_ERR         3
#  define LOG_WARNING     4
#  define LOG_NOTICE      5
#  define LOG_INFO        6
#  define LOG_DEBUG       7
#  define LOG_DAEMON      OPC$M_NM_NTWORK
# endif
static int slg_free(BIO *a)
{
    if (a == NULL)
        return 0;
    xcloselog(a);
    return 1;
}
# if defined(OPENSSL_SYS_WIN32)
# elif defined(OPENSSL_SYS_VMS)
#  if __INITIAL_POINTER_SIZE == 64
#   pragma pointer_size save
#   pragma pointer_size 32
#   define OPCDEF_TYPE __char_ptr32
#   define OPCDEF_MALLOC _malloc32
#  else                         /* __INITIAL_POINTER_SIZE == 64 */
#   define OPCDEF_TYPE char *
#   define OPCDEF_MALLOC OPENSSL_malloc
#  endif                        /* __INITIAL_POINTER_SIZE == 64 [else] */
#  if __INITIAL_POINTER_SIZE == 64
#   pragma pointer_size restore
#  endif                        /* __INITIAL_POINTER_SIZE == 64 */
# else                          /* Unix/Watt32 */
#  ifdef WATT32                 /* djgpp/DOS */
#  else
#  endif
# endif                         /* Unix */
#else                           /* NO_SYSLOG */
#endif                          /* NO_SYSLOG */
