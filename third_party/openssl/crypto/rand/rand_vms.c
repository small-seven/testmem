#include "e_os.h"
#if defined(OPENSSL_SYS_VMS)
# define __NEW_STARLET 1         /* New starlet definitions since VMS 7.0 */
# include <unistd.h>
# include "internal/cryptlib.h"
# include <openssl/bio.h>
# include <openssl/err.h>
# include <openssl/rand.h>
# include "crypto/rand.h"
# include "rand_local.h"
# include <descrip.h>
# include <dvidef.h>
# include <jpidef.h>
# include <rmidef.h>
# include <syidef.h>
# include <ssdef.h>
# include <starlet.h>
# include <efndef.h>
# include <gen64def.h>
# include <iosbdef.h>
# include <iledef.h>
# include <lib$routines.h>
# ifdef __DECC
#  pragma message disable DOLLARID
# endif
# include <dlfcn.h>              /* SYS$GET_ENTROPY presence */
# ifndef OPENSSL_RAND_SEED_OS
#  error "Unsupported seeding method configured; must be os"
# endif
# if __INITIAL_POINTER_SIZE == 64
#  pragma pointer_size save
#  pragma pointer_size 32
# endif
typedef uint32_t *uint32_t__ptr32;
# if __INITIAL_POINTER_SIZE == 64
#  pragma pointer_size restore
# endif

struct item_st {
    short length, code;         /* length is number of bytes */
};
#if defined __alpha
#endif
#if 0
#endif
#if defined __alpha
#endif
#if defined __ia64
#endif
#if defined __ia64
#endif
#define ENTROPY_FACTOR  20
#if __CRTL_VER >= 80400000
#else
#endif
#define PUBLIC_VECTORS "SYS$LIBRARY:SYS$PUBLIC_VECTORS.EXE"
#define GET_ENTROPY "SYS$GET_ENTROPY"
#if __CRTL_VER >= 80400000
#else
#endif
#endif
