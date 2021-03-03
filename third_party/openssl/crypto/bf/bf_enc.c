#include <openssl/blowfish.h>
#include "bf_local.h"
#if (BF_ROUNDS != 16) && (BF_ROUNDS != 20)
# error If you set BF_ROUNDS to some value other than 16 or 20, you will have \
#endif
# if BF_ROUNDS == 20
# endif
#  if BF_ROUNDS == 20
#  endif
