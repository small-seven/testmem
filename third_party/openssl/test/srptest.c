#include <openssl/opensslconf.h>
# include "testutil.h"
#ifdef OPENSSL_NO_SRP
# include <stdio.h>
#else
# include <openssl/srp.h>
# include <openssl/rand.h>
# include <openssl/err.h>
# define RANDOM_SIZE 32         /* use 256 bits on each side */
#endif
#ifdef OPENSSL_NO_SRP
#else
#endif
