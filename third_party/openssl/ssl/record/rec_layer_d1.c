#include <stdio.h>
#include <errno.h>
#include "../ssl_local.h"
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include "record_local.h"
#include "../packet_local.h"
#include "internal/cryptlib.h"
void DTLS_RECORD_LAYER_free(RECORD_LAYER *rl)
{
    DTLS_RECORD_LAYER_clear(rl);
    pqueue_free(rl->d->unprocessed_rcds.q);
    pqueue_free(rl->d->processed_rcds.q);
    pqueue_free(rl->d->buffered_app_data.q);
    OPENSSL_free(rl->d);
    rl->d = NULL;
}
#ifndef OPENSSL_NO_SCTP
#endif
#define dtls1_get_unprocessed_record(s) \
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
