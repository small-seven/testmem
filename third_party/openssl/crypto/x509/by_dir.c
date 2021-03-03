#include "e_os.h"
#include "internal/cryptlib.h"
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#ifndef OPENSSL_NO_POSIX_IO
# include <sys/stat.h>
#endif
#include <openssl/x509.h>
#include "crypto/x509.h"
#include "x509_local.h"
typedef struct lookup_dir_st {
    BUF_MEM *buffer;
    STACK_OF(BY_DIR_ENTRY) *dirs;
    CRYPTO_RWLOCK *lock;
} BY_DIR;
static void by_dir_hash_free(BY_DIR_HASH *hash)
{
    OPENSSL_free(hash);
}
static void by_dir_entry_free(BY_DIR_ENTRY *ent)
{
    OPENSSL_free(ent->dir);
    sk_BY_DIR_HASH_pop_free(ent->hashes, by_dir_hash_free);
    OPENSSL_free(ent);
}
#ifdef OPENSSL_SYS_VMS
#endif
#ifndef OPENSSL_NO_POSIX_IO
# ifdef _WIN32
#  define stat _stat
# endif
#endif
