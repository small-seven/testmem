#include "internal/nelem.h"
#include "testutil.h"
#ifndef OPENSSL_NO_EC
# include <openssl/ec.h>
# ifndef OPENSSL_NO_ENGINE
#  include <openssl/engine.h>
# endif
# include <openssl/err.h>
# include <openssl/obj_mac.h>
# include <openssl/objects.h>
# include <openssl/rand.h>
# include <openssl/bn.h>
# include <openssl/opensslconf.h>
# ifndef OPENSSL_NO_EC2M
# ifdef OPENSSL_EC_BIN_PT_COMP
# else
# endif
#  ifdef OPENSSL_EC_BIN_PT_COMP
#  else
#  endif
#  ifdef OPENSSL_EC_BIN_PT_COMP
#  endif
#  ifdef OPENSSL_EC_BIN_PT_COMP
#  endif
#  ifdef OPENSSL_EC_BIN_PT_COMP
#  endif
# endif
# ifndef OPENSSL_NO_EC_NISTP_64_GCC_128
# endif
# ifndef OPENSSL_NO_EC2M
# endif /* OPENSSL_NO_EC2M */
# ifdef OPENSSL_NO_EC_NISTP_64_GCC_128
# else
# endif /* def(OPENSSL_NO_EC_NISTP_64_GCC_128) */
#endif /* OPENSSL_NO_EC */
#ifndef OPENSSL_NO_EC
# ifndef OPENSSL_NO_EC2M
# endif
# ifndef OPENSSL_NO_EC_NISTP_64_GCC_128
# endif
#endif /* OPENSSL_NO_EC */
#ifndef OPENSSL_NO_EC
#endif
