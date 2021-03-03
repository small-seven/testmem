#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <openssl/bn.h>
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include "internal/nelem.h"
#include "internal/numbers.h"
#include "testutil.h"
#ifdef OPENSSL_SYS_WINDOWS
# define strcasecmp _stricmp
#endif
#define HAVE_BN_PADDED 0
#define HAVE_BN_SQRT 0
typedef struct filetest_st {
    const char *name;
    int (*func)(STANZA *s);
} FILETEST;
typedef struct mpitest_st {
    const char *base10;
    const char *mpi;
    size_t mpi_len;
} MPITEST;
#ifndef OPENSSL_NO_EC2M
#endif
#ifndef OPENSSL_NO_EC2M
#endif
#if HAVE_BN_SQRT
#endif
#ifdef BN_DEC_FMT1
#else
#endif
#ifdef BN_DEC_FMT1
#else
#endif
#if HAVE_BN_PADDED
# define TOP_BIT_ON 0
# define BOTTOM_BIT_NOTOUCH 0
#else
#endif
typedef struct mod_exp_test_st
{
  const char *base;
  const char *exp;
  const char *mod;
  const char *res;
} MOD_EXP_TEST;
#ifndef OPENSSL_NO_EC2M
#endif
