#include <openssl/crypto.h>
#include "des_local.h"
#define NUM_WEAK_KEY    16
#define HPERM_OP(a,t,n,m) ((t)=((((a)<<(16-(n)))^(a))&(m)),\
#ifdef OPENBSD_DEV_CRYPTO
#endif
