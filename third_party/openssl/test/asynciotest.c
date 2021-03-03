#include <string.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include "../ssl/packet_local.h"
#include "ssltestlib.h"
#include "testutil.h"
# define BIO_TYPE_ASYNC_FILTER  (0x80 | BIO_TYPE_FILTER)
static int async_free(BIO *bio)
{
    struct async_ctrs *ctrs;

    if (bio == NULL)
        return 0;
    ctrs = BIO_get_data(bio);
    OPENSSL_free(ctrs);
    BIO_set_data(bio, NULL);
    BIO_set_init(bio, 0);

    return 1;
}
#define MIN_RECORD_LEN  6
#define CONTENTTYPEPOS  0
#define VERSIONHIPOS    1
#define VERSIONLOPOS    2
#define DATAPOS         5
#define MAX_ATTEMPTS    100
