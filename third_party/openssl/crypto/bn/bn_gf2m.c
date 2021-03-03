#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include "internal/cryptlib.h"
#include "bn_local.h"
#ifndef OPENSSL_NO_EC2M
# define MAX_ITERATIONS 50
# define SQR_nibble(w)   ((((w) & 8) << 3) \
# if defined(SIXTY_FOUR_BIT) || defined(SIXTY_FOUR_BIT_LONG)
#  define SQR1(w) \
#  define SQR0(w) \
# endif
# ifdef THIRTY_TWO_BIT
#  define SQR1(w) \
#  define SQR0(w) \
# endif
# if !defined(OPENSSL_BN_ASM_GF2m)
#  ifdef THIRTY_TWO_BIT
#  endif
#  if defined(SIXTY_FOUR_BIT) || defined(SIXTY_FOUR_BIT_LONG)
#  endif
# else
# endif
# if 0
# else
# endif
# ifdef BN_DEBUG                /* BN_CTX_end would complain about the
# endif
#endif
