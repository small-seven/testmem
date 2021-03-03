#include <openssl/crypto.h>
#include "word.h"
#include "point_448.h"
#define WBITS C448_WORD_BITS   /* NB this may be different from ARCH_WORD_BITS */
void curve448_scalar_destroy(curve448_scalar_t scalar)
{
    OPENSSL_cleanse(scalar, sizeof(curve448_scalar_t));
}
