#include "internal/cryptlib.h"
#include "bn_local.h"
#define BN_lsw(n) (((n)->top == 0) ? (BN_ULONG) 0 : (n)->d[0])
