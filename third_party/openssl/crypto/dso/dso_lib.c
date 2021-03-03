#include "dso_local.h"
#include "internal/refcount.h"
int DSO_free(DSO *dso)
{
    int i;

    if (dso == NULL)
        return 1;

    if (CRYPTO_DOWN_REF(&dso->references, &i, dso->lock) <= 0)
        return 0;

    REF_PRINT_COUNT("DSO", dso);
    if (i > 0)
        return 1;
    REF_ASSERT_ISNT(i < 0);

    if ((dso->flags & DSO_FLAG_NO_UNLOAD_ON_FREE) == 0) {
        if ((dso->meth->dso_unload != NULL) && !dso->meth->dso_unload(dso)) {
            DSOerr(DSO_F_DSO_FREE, DSO_R_UNLOAD_FAILED);
            return 0;
        }
    }

    if ((dso->meth->finish != NULL) && !dso->meth->finish(dso)) {
        DSOerr(DSO_F_DSO_FREE, DSO_R_FINISH_FAILED);
        return 0;
    }

    sk_void_free(dso->meth_data);
    OPENSSL_free(dso->filename);
    OPENSSL_free(dso->loaded_filename);
    CRYPTO_THREAD_lock_free(dso->lock);
    OPENSSL_free(dso);
    return 1;
}
