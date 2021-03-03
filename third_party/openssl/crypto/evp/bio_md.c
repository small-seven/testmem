#include <stdio.h>
#include <errno.h>
#include "internal/cryptlib.h"
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include "crypto/evp.h"
#include "evp_local.h"
#include "internal/bio.h"
static int md_free(BIO *a)
{
    if (a == NULL)
        return 0;
    EVP_MD_CTX_free(BIO_get_data(a));
    BIO_set_data(a, NULL);
    BIO_set_init(a, 0);

    return 1;
}
