#include <string.h>
#include "ssltestlib.h"
#include "testutil.h"
static int tls_corrupt_free(BIO *bio)
{
    BIO_set_init(bio, 0);

    return 1;
}
#define BIO_TYPE_CUSTOM_FILTER  (0x80 | BIO_TYPE_FILTER)
static void bio_f_tls_corrupt_filter_free(void)
{
    BIO_meth_free(method_tls_corrupt);
}
