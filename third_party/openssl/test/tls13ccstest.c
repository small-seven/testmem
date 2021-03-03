#include <openssl/ssl.h>
#include <string.h>
#include "ssltestlib.h"
#include "testutil.h"
#include "../ssl/packet_local.h"
# define BIO_TYPE_WATCHCCS_FILTER  (0x80 | BIO_TYPE_FILTER)
static int watchccs_free(BIO *bio)
{
    BIO_set_init(bio, 0);
    return 1;
}
