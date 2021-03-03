#include "bn_local.h"
#include "internal/nelem.h"
#ifndef OPENSSL_NO_DH
#include <openssl/dh.h>
#include "crypto/bn_dh.h"
# if BN_BITS2 == 64
# elif BN_BITS2 == 32
# else
#  error "unsupported BN_BITS2"
# endif
# define make_dh_bn(x) extern const BIGNUM _bignum_##x; \
#endif
