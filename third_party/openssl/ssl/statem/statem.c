#include "internal/cryptlib.h"
#include <openssl/rand.h>
#include "../ssl_local.h"
#include "statem_local.h"
#include <assert.h>
typedef enum {
    /* Something bad happened or NBIO */
    SUB_STATE_ERROR,
    /* Sub state finished go to the next sub state */
    SUB_STATE_FINISHED,
    /* Sub state finished and handshake was completed */
    SUB_STATE_END_HANDSHAKE
} SUB_STATE_RETURN;
#define check_fatal(s, f) \
typedef void (*info_cb) (const SSL *, int, int);

static info_cb get_callback(SSL *s)
{
    if (s->info_callback != NULL)
        return s->info_callback;
    else if (s->ctx->info_callback != NULL)
        return s->ctx->info_callback;

    return NULL;
}
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
