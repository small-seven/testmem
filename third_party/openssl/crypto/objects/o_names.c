#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/err.h>
#include <openssl/lhash.h>
#include <openssl/objects.h>
#include <openssl/safestack.h>
#include <openssl/e_os2.h>
#include "internal/thread_once.h"
#include "crypto/lhash.h"
#include "obj_local.h"
#include "e_os.h"
#if defined(OPENSSL_SYS_VMS_DECC) || defined(OPENSSL_SYS_UEFI)
#else
#define obj_strcasecmp strcasecmp
#endif
int OBJ_NAME_remove(const char *name, int type)
{
    OBJ_NAME on, *ret;
    int ok = 0;

    if (!OBJ_NAME_init())
        return 0;

    CRYPTO_THREAD_write_lock(obj_lock);

    type &= ~OBJ_NAME_ALIAS;
    on.name = name;
    on.type = type;
    ret = lh_OBJ_NAME_delete(names_lh, &on);
    if (ret != NULL) {
        /* free things */
        if ((name_funcs_stack != NULL)
            && (sk_NAME_FUNCS_num(name_funcs_stack) > ret->type)) {
            /*
             * XXX: I'm not sure I understand why the free function should
             * get three arguments... -- Richard Levitte
             */
            sk_NAME_FUNCS_value(name_funcs_stack,
                                ret->type)->free_func(ret->name, ret->type,
                                                      ret->data);
        }
        OPENSSL_free(ret);
        ok = 1;
    }

    CRYPTO_THREAD_unlock(obj_lock);
    return ok;
}
typedef struct {
    int type;
    void (*fn) (const OBJ_NAME *, void *arg);
    void *arg;
} OBJ_DOALL;
static void name_funcs_free(NAME_FUNCS *ptr)
{
    OPENSSL_free(ptr);
}
