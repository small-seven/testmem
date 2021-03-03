#include "eng_local.h"
static int engine_list_remove(ENGINE *e)
{
    ENGINE *iterator;

    if (e == NULL) {
        ENGINEerr(ENGINE_F_ENGINE_LIST_REMOVE, ERR_R_PASSED_NULL_PARAMETER);
        return 0;
    }
    /* We need to check that e is in our linked list! */
    iterator = engine_list_head;
    while (iterator && (iterator != e))
        iterator = iterator->next;
    if (iterator == NULL) {
        ENGINEerr(ENGINE_F_ENGINE_LIST_REMOVE,
                  ENGINE_R_ENGINE_IS_NOT_IN_LIST);
        return 0;
    }
    /* un-link e from the chain. */
    if (e->next)
        e->next->prev = e->prev;
    if (e->prev)
        e->prev->next = e->next;
    /* Correct our head/tail if necessary. */
    if (engine_list_head == e)
        engine_list_head = e->next;
    if (engine_list_tail == e)
        engine_list_tail = e->prev;
    engine_free_util(e, 0);
    return 1;
}
int ENGINE_remove(ENGINE *e)
{
    int to_return = 1;
    if (e == NULL) {
        ENGINEerr(ENGINE_F_ENGINE_REMOVE, ERR_R_PASSED_NULL_PARAMETER);
        return 0;
    }
    CRYPTO_THREAD_write_lock(global_engine_lock);
    if (!engine_list_remove(e)) {
        ENGINEerr(ENGINE_F_ENGINE_REMOVE, ENGINE_R_INTERNAL_LIST_ERROR);
        to_return = 0;
    }
    CRYPTO_THREAD_unlock(global_engine_lock);
    return to_return;
}
#ifndef OPENSSL_NO_RSA
#endif
#ifndef OPENSSL_NO_DSA
#endif
#ifndef OPENSSL_NO_DH
#endif
#ifndef OPENSSL_NO_EC
#endif
