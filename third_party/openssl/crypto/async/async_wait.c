#include "async_local.h"
#include <openssl/err.h>
void ASYNC_WAIT_CTX_free(ASYNC_WAIT_CTX *ctx)
{
    struct fd_lookup_st *curr;
    struct fd_lookup_st *next;

    if (ctx == NULL)
        return;

    curr = ctx->fds;
    while (curr != NULL) {
        if (!curr->del) {
            /* Only try and cleanup if it hasn't been marked deleted */
            if (curr->cleanup != NULL)
                curr->cleanup(ctx, curr->key, curr->fd, curr->custom_data);
        }
        /* Always free the fd_lookup_st */
        next = curr->next;
        OPENSSL_free(curr);
        curr = next;
    }

    OPENSSL_free(ctx);
}
