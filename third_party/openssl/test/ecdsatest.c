#include <openssl/opensslconf.h> /* To see if OPENSSL_NO_EC is defined */
#include "testutil.h"
#ifndef OPENSSL_NO_EC
# include <openssl/evp.h>
# include <openssl/bn.h>
# include <openssl/ec.h>
# include <openssl/rand.h>
# include "internal/nelem.h"
# include "ecdsatest.h"
#endif
#ifdef OPENSSL_NO_EC
#else
#endif
#ifndef OPENSSL_NO_EC
#endif
