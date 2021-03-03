#include "bio_local.h"
#include "internal/thread_once.h"
void BIO_meth_free(BIO_METHOD *biom)
{
    if (biom != NULL) {
        OPENSSL_free(biom->name);
        OPENSSL_free(biom);
    }
}
int (*BIO_meth_get_destroy(const BIO_METHOD *biom)) (BIO *)
{
    return biom->destroy;
}
int BIO_meth_set_destroy(BIO_METHOD *biom, int (*destroy) (BIO *))
{
    biom->destroy = destroy;
    return 1;
}
