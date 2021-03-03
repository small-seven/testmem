#include "e_os.h"
#include <limits.h>
#include <openssl/crypto.h>
#include "internal/cryptlib.h"
#include "internal/o_str.h"
int OPENSSL_memcmp(const void *v1, const void *v2, size_t n)
{
    const unsigned char *c1 = v1, *c2 = v2;
    int ret = 0;

    while (n && (ret = *c1 - *c2) == 0)
        n--, c1++, c2++;

    return ret;
}
#ifdef CHARSET_EBCDIC
#endif
#ifdef CHARSET_EBCDIC
#endif
#if defined(_MSC_VER) && _MSC_VER>=1400
#elif defined(_GNU_SOURCE)
#elif (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 200112L) || \
#else
#endif
