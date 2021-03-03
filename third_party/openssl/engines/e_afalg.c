#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <openssl/engine.h>
#include <openssl/async.h>
#include <openssl/err.h>
#include "internal/nelem.h"
#include <sys/socket.h>
#include <linux/version.h>
#define K_MAJ   4
#define K_MIN1  1
#define K_MIN2  0
#if LINUX_VERSION_CODE < KERNEL_VERSION(K_MAJ, K_MIN1, K_MIN2) || \
# ifndef PEDANTIC
#  warning "AFALG ENGINE requires Kernel Headers >= 4.1.0"
#  warning "Skipping Compilation of AFALG engine"
# endif
#else
# include <linux/if_alg.h>
# include <fcntl.h>
# include <sys/utsname.h>
# include <linux/aio_abi.h>
# include <sys/syscall.h>
# include <errno.h>
# include "e_afalg.h"
# include "e_afalg_err.c"
# ifndef SOL_ALG
#  define SOL_ALG 279
# endif
# ifdef ALG_ZERO_COPY
#  ifndef SPLICE_F_GIFT
#   define SPLICE_F_GIFT    (0x08)
#  endif
# endif
# define ALG_AES_IV_LEN 16
# define ALG_IV_LEN(len) (sizeof(struct af_alg_iv) + (len))
# define ALG_OP_TYPE     unsigned int
# define ALG_OP_LEN      (sizeof(ALG_OP_TYPE))
# ifdef OPENSSL_NO_DYNAMIC_ENGINE
# endif
static ossl_inline int io_destroy(aio_context_t ctx)
{
    return syscall(__NR_io_destroy, ctx);
}
# ifdef ALG_ZERO_COPY
# endif
# ifdef ALG_ZERO_COPY
# else
# endif
# ifdef ALG_ZERO_COPY
# endif
# ifdef ALG_ZERO_COPY
# endif
# ifndef OPENSSL_NO_DYNAMIC_ENGINE
# endif
# ifdef OPENSSL_NO_DYNAMIC_ENGINE
# endif
static int afalg_destroy(ENGINE *e)
{
    ERR_unload_AFALG_strings();
    free_cbc();
    return 1;
}
#endif                          /* KERNEL VERSION */
