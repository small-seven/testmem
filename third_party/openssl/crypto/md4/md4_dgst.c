#include <stdio.h>
#include <openssl/opensslv.h>
#include "md4_local.h"
#define INIT_DATA_A (unsigned long)0x67452301L
#define INIT_DATA_B (unsigned long)0xefcdab89L
#define INIT_DATA_C (unsigned long)0x98badcfeL
#define INIT_DATA_D (unsigned long)0x10325476L
#ifndef md4_block_data_order
# ifdef X
#  undef X
# endif
# ifndef MD32_XARRAY
#  define X(i)   XX##i
# else
#  define X(i)   XX[i]
# endif
#endif
