#include "bn_local.h"
#include "internal/nelem.h"
#ifndef OPENSSL_NO_SRP
#include <openssl/srp.h>
#include "crypto/bn_srp.h"
# if (BN_BYTES == 8)
#  if (defined(_WIN32) || defined(_WIN64)) && !defined(__MINGW32__)
#   define bn_pack4(a1,a2,a3,a4) ((a1##UI64<<48)|(a2##UI64<<32)|(a3##UI64<<16)|a4##UI64)
#  elif defined(__arch64__)
#   define bn_pack4(a1,a2,a3,a4) ((a1##UL<<48)|(a2##UL<<32)|(a3##UL<<16)|a4##UL)
#  else
#   define bn_pack4(a1,a2,a3,a4) ((a1##ULL<<48)|(a2##ULL<<32)|(a3##ULL<<16)|a4##ULL)
#  endif
# elif (BN_BYTES == 4)
#  define bn_pack4(a1,a2,a3,a4)  ((a3##UL<<16)|a4##UL), ((a1##UL<<16)|a2##UL)
# else
#  error "unsupported BN_BYTES"
# endif
#endif
