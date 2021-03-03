#include <assert.h>
#include <string.h>
#include <openssl/crypto.h>
#include "blake2_local.h"
#include "blake2_impl.h"
#define G(r,i,a,b,c,d) \
#define ROUND(r)  \
#if defined(OPENSSL_SMALL_FOOTPRINT)
#else
#endif
#undef G
#undef ROUND
