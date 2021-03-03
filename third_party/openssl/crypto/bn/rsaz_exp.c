#include <openssl/opensslconf.h>
#include "rsaz_exp.h"
#ifndef RSAZ_ENABLED
#else
#if defined(__GNUC__)
# define ALIGN64        __attribute__((aligned(64)))
#elif defined(_MSC_VER)
# define ALIGN64        __declspec(align(64))
#elif defined(__SUNPRO_C)
# define ALIGN64
# pragma align 64(one,two80)
#else
# define ALIGN64
#endif
#if 0
#else
#endif
#endif
