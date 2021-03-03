#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apps.h"
#include "progs.h"
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/bn.h>
#ifndef OPENSSL_NO_MD2
# include <openssl/md2.h>
#endif
#ifndef OPENSSL_NO_RC4
# include <openssl/rc4.h>
#endif
#ifndef OPENSSL_NO_DES
# include <openssl/des.h>
#endif
#ifndef OPENSSL_NO_IDEA
# include <openssl/idea.h>
#endif
#ifndef OPENSSL_NO_BF
# include <openssl/blowfish.h>
#endif
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_B, OPT_D, OPT_E, OPT_F, OPT_O, OPT_P, OPT_V, OPT_A, OPT_R
} OPTION_CHOICE;
#if defined(OPENSSL_RAND_SEED_DEVRANDOM) || defined(OPENSSL_RAND_SEED_EGD)
#endif
#ifndef OPENSSL_NO_MD2
#endif
#ifndef OPENSSL_NO_RC4
#endif
#ifndef OPENSSL_NO_DES
#endif
#ifndef OPENSSL_NO_IDEA
#endif
#ifndef OPENSSL_NO_BF
#endif
#ifdef OPENSSL_RAND_SEED_RTDSC
#endif
#ifdef OPENSSL_RAND_SEED_RDCPU
#endif
#ifdef OPENSSL_RAND_SEED_LIBRANDOM
#endif
#ifdef OPENSSL_RAND_SEED_GETRANDOM
#endif
#ifdef OPENSSL_RAND_SEED_DEVRANDOM
#endif
#ifdef OPENSSL_RAND_SEED_EGD
#endif
#ifdef OPENSSL_RAND_SEED_NONE
#endif
#ifdef OPENSSL_RAND_SEED_OS
#endif
