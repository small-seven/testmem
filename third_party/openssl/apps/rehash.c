#include "apps.h"
#include "progs.h"
#if defined(OPENSSL_SYS_UNIX) || defined(__APPLE__) || \
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <ctype.h>
# include <sys/stat.h>
# ifdef __VMS
#  pragma names save
#  pragma names as_is,shortened
# endif
# include "internal/o_dir.h"
# ifdef __VMS
#  pragma names restore
# endif
# include <openssl/evp.h>
# include <openssl/pem.h>
# include <openssl/x509.h>
# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif
# ifndef NAME_MAX
#  define NAME_MAX 255
# endif
# define MAX_COLLISIONS  256
# if defined(OPENSSL_SYS_VXWORKS)
#  define lstat(path, buf) stat(path, buf)
# endif
typedef struct hentry_st {
    struct hentry_st *next;
    char *filename;
    unsigned short old_id;
    unsigned char need_symlink;
    unsigned char digest[EVP_MAX_MD_SIZE];
} HENTRY;
typedef struct bucket_st {
    struct bucket_st *next;
    HENTRY *first_entry, *last_entry;
    unsigned int hash;
    unsigned short type;
    unsigned short num_needed;
} BUCKET;
static void str_free(char *s)
{
    OPENSSL_free(s);
}
# if defined __VMS
# elif defined _WIN32
# endif
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_COMPAT, OPT_OLD, OPT_N, OPT_VERBOSE
} OPTION_CHOICE;
#else
#endif /* defined(OPENSSL_SYS_UNIX) || defined(__APPLE__) */
