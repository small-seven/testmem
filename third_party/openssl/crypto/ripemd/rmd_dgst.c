#include <stdio.h>
#include "rmd_local.h"
#include <openssl/opensslv.h>
#ifdef RMD160_ASM
# define ripemd160_block ripemd160_block_x86
#else
#endif
#ifndef ripemd160_block_data_order
# ifdef X
#  undef X
# endif
# ifndef MD32_XARRAY
#  define X(i)   XX##i
# else
#  define X(i)   XX[i]
# endif
#endif
