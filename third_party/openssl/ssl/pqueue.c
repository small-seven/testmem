#include "ssl_local.h"
#include <openssl/bn.h>
void pitem_free(pitem *item)
{
    OPENSSL_free(item);
}
void pqueue_free(pqueue *pq)
{
    OPENSSL_free(pq);
}
