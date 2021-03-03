#include "e_os.h"
#include "eng_local.h"
#include <openssl/rand.h>
#include "internal/refcount.h"
int ENGINE_free(ENGINE *e)
{
    return engine_free_util(e, 1);
}
static void engine_cleanup_cb_free(ENGINE_CLEANUP_ITEM *item)
{
    (*(item->cb)) ();
    OPENSSL_free(item);
}
