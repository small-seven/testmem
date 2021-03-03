#include <assert.h>
#include "internal/cryptlib.h"
#include "bn_local.h"
#if defined(OPENSSL_NO_ASM) || !defined(OPENSSL_BN_ASM_PART_WORDS)
#endif
#ifdef BN_RECURSION
# ifdef BN_MUL_COMBA
#  if 0
#  endif
# endif                         /* BN_MUL_COMBA */
# ifdef BN_MUL_COMBA
# endif                         /* BN_MUL_COMBA */
# if 0
# endif
#endif                          /* BN_RECURSION */
#if defined(BN_MUL_COMBA) || defined(BN_RECURSION)
#endif
#ifdef BN_RECURSION
#endif
#if defined(BN_MUL_COMBA) || defined(BN_RECURSION)
#endif
#ifdef BN_MUL_COMBA
# if 0
# endif
#endif                          /* BN_MUL_COMBA */
#ifdef BN_RECURSION
#endif                          /* BN_RECURSION */
#if defined(BN_MUL_COMBA) || defined(BN_RECURSION)
#endif
