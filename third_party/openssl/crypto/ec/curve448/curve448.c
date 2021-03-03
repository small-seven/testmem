#include <openssl/crypto.h>
#include "word.h"
#include "field.h"
#include "point_448.h"
#include "ed448.h"
#include "curve448_local.h"
#define COFACTOR 4
#define C448_WNAF_FIXED_TABLE_BITS 5
#define C448_WNAF_VAR_TABLE_BITS 3
#define EDWARDS_D       (-39081)
#define TWISTED_D (EDWARDS_D - 1)
#define WBITS C448_WORD_BITS   /* NB this may be different from ARCH_WORD_BITS */
#if defined(__GNUC__) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 3))
# define NUMTRAILINGZEROS	__builtin_ctz
#else
# define NUMTRAILINGZEROS	numtrailingzeros
#endif
void curve448_point_destroy(curve448_point_t point)
{
    OPENSSL_cleanse(point, sizeof(curve448_point_t));
}
