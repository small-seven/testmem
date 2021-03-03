#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_EC_NISTP_64_GCC_128
#else
# include <stddef.h>
# include "ec_local.h"
# define tmp_felem(I) (&((char *)tmp_felems)[(I) * felem_size])
# define X(I) (&((char *)point_array)[3*(I) * felem_size])
# define Y(I) (&((char *)point_array)[(3*(I) + 1) * felem_size])
# define Z(I) (&((char *)point_array)[(3*(I) + 2) * felem_size])
#endif
