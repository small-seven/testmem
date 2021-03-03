#ifndef OPENSSL_NO_SEED
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# ifdef _WIN32
#  include <memory.h>
# endif
# include <openssl/seed.h>
# include "seed_local.h"
# ifdef SS                      /* can get defined on Solaris by inclusion of
#  undef SS
# endif
# if !defined(OPENSSL_SMALL_FOOTPRINT)
#  define G_FUNC(v)       \
#else
# endif
# define KC0     0x9e3779b9
# define KC1     0x3c6ef373
# define KC2     0x78dde6e6
# define KC3     0xf1bbcdcc
# define KC4     0xe3779b99
# define KC5     0xc6ef3733
# define KC6     0x8dde6e67
# define KC7     0x1bbcdccf
# define KC8     0x3779b99e
# define KC9     0x6ef3733c
# define KC10    0xdde6e678
# define KC11    0xbbcdccf1
# define KC12    0x779b99e3
# define KC13    0xef3733c6
# define KC14    0xde6e678d
# define KC15    0xbcdccf1b
# if defined(OPENSSL_SMALL_FOOTPRINT)
# endif
# if !defined(OPENSSL_SMALL_FOOTPRINT)
# else
# endif
# if !defined(OPENSSL_SMALL_FOOTPRINT)
# else
# endif
# if !defined(OPENSSL_SMALL_FOOTPRINT)
# else
# endif
#endif                          /* OPENSSL_NO_SEED */
