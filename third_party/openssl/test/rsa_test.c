#include <stdio.h>
#include <string.h>
#include "internal/nelem.h"
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/bn.h>
#include "testutil.h"
#ifdef OPENSSL_NO_RSA
#else
# include <openssl/rsa.h>
# define SetKey \
#endif
