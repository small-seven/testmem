#include <string.h>
#include "internal/nelem.h"
#include "ssltestlib.h"
#include "testutil.h"
#include "e_os.h"
#ifdef OPENSSL_SYS_UNIX
# include <unistd.h>
# ifdef OPENSSL_SYS_VXWORKS
# else
# endif
#elif defined(_WIN32)
# include <windows.h>
#else
#endif
#define BIO_TYPE_TLS_DUMP_FILTER  (0x80 | BIO_TYPE_FILTER)
#define BIO_TYPE_MEMPACKET_TEST    0x81
#define BIO_TYPE_ALWAYS_RETRY      0x82
void bio_f_tls_dump_filter_free(void)
{
    BIO_meth_free(method_tls_dump);
}
static int tls_dump_free(BIO *bio)
{
    BIO_set_init(bio, 0);

    return 1;
}
#define RECORD_CONTENT_TYPE     0
#define RECORD_VERSION_HI       1
#define RECORD_VERSION_LO       2
#define RECORD_EPOCH_HI         3
#define RECORD_EPOCH_LO         4
#define RECORD_SEQUENCE_START   5
#define RECORD_SEQUENCE_END     10
#define RECORD_LEN_HI           11
#define RECORD_LEN_LO           12
#define MSG_TYPE                0
#define MSG_LEN_HI              1
#define MSG_LEN_MID             2
#define MSG_LEN_LO              3
#define MSG_SEQ_HI              4
#define MSG_SEQ_LO              5
#define MSG_FRAG_OFF_HI         6
#define MSG_FRAG_OFF_MID        7
#define MSG_FRAG_OFF_LO         8
#define MSG_FRAG_LEN_HI         9
#define MSG_FRAG_LEN_MID        10
#define MSG_FRAG_LEN_LO         11
static void mempacket_free(MEMPACKET *pkt)
{
    if (pkt->data != NULL)
        OPENSSL_free(pkt->data);
    OPENSSL_free(pkt);
}
typedef struct mempacket_test_ctx_st {
    STACK_OF(MEMPACKET) *pkts;
    unsigned int epoch;
    unsigned int currrec;
    unsigned int currpkt;
    unsigned int lastpkt;
    unsigned int injected;
    unsigned int noinject;
    unsigned int dropepoch;
    int droprec;
    int duprec;
} MEMPACKET_TEST_CTX;
void bio_s_mempacket_test_free(void)
{
    BIO_meth_free(meth_mem);
}
static int mempacket_test_free(BIO *bio)
{
    MEMPACKET_TEST_CTX *ctx = BIO_get_data(bio);

    sk_MEMPACKET_pop_free(ctx->pkts, mempacket_free);
    OPENSSL_free(ctx);
    BIO_set_data(bio, NULL);
    BIO_set_init(bio, 0);
    return 1;
}
#define EPOCH_HI        3
#define EPOCH_LO        4
#define RECORD_SEQUENCE 10
#define RECORD_LEN_HI   11
#define RECORD_LEN_LO   12
#define STANDARD_PACKET                 0
void bio_s_always_retry_free(void)
{
    BIO_meth_free(meth_always_retry);
}
static int always_retry_free(BIO *bio)
{
    BIO_set_data(bio, NULL);
    BIO_set_init(bio, 0);
    return 1;
}
#ifndef OPENSSL_NO_DH
#endif
#define MAXLOOPS    1000000
