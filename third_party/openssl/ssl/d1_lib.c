#include "e_os.h"
#include <stdio.h>
#include <openssl/objects.h>
#include <openssl/rand.h>
#include "ssl_local.h"
void dtls1_free(SSL *s)
{
    DTLS_RECORD_LAYER_free(&s->rlayer);

    ssl3_free(s);

    dtls1_clear_queues(s);

    pqueue_free(s->d1->buffered_messages);
    pqueue_free(s->d1->sent_messages);

    OPENSSL_free(s->d1);
    s->d1 = NULL;
}
#ifndef OPENSSL_NO_DTLS1_METHOD
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#if defined(_WIN32)
# ifdef  __MINGW32__
# else
# endif
#else
#endif
#define LISTEN_SUCCESS              2
#define LISTEN_SEND_VERIFY_REQUEST  1
#ifndef OPENSSL_NO_SOCK
#if defined(SSL3_ALIGN_PAYLOAD)
# if SSL3_ALIGN_PAYLOAD != 0
# endif
#endif
#endif
#ifndef OPENSSL_NO_SCTP
#endif
#ifndef OPENSSL_NO_SCTP
#endif
