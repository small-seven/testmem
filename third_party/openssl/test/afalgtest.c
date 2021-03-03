#include <stdio.h>
#include <openssl/opensslconf.h>
#include <string.h>
#include <openssl/engine.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include "testutil.h"
#define BUFFER_SIZE     17
#ifndef OPENSSL_NO_ENGINE
#endif
#ifndef OPENSSL_NO_AFALGENG
# include <linux/version.h>
# define K_MAJ   4
# define K_MIN1  1
# define K_MIN2  0
# if LINUX_VERSION_CODE < KERNEL_VERSION(K_MAJ, K_MIN1, K_MIN2)
#  define OPENSSL_NO_AFALGENG
# endif
#endif
#ifndef OPENSSL_NO_AFALGENG
#endif
#ifndef OPENSSL_NO_ENGINE
# ifndef OPENSSL_NO_STATIC_ENGINE
# endif
#endif
#ifndef OPENSSL_NO_ENGINE
# ifndef OPENSSL_NO_AFALGENG
# endif
#endif
#ifndef OPENSSL_NO_ENGINE
#endif
