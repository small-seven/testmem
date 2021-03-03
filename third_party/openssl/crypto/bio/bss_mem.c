#include <stdio.h>
#include <errno.h>
#include "bio_local.h"
#include "internal/cryptlib.h"
typedef struct bio_buf_mem_st {
    struct buf_mem_st *buf;   /* allocated buffer */
    struct buf_mem_st *readp; /* read pointer */
} BIO_BUF_MEM;
static int mem_init(BIO *bi, unsigned long flags)
{
    BIO_BUF_MEM *bb = OPENSSL_zalloc(sizeof(*bb));

    if (bb == NULL)
        return 0;
    if ((bb->buf = BUF_MEM_new_ex(flags)) == NULL) {
        OPENSSL_free(bb);
        return 0;
    }
    if ((bb->readp = OPENSSL_zalloc(sizeof(*bb->readp))) == NULL) {
        BUF_MEM_free(bb->buf);
        OPENSSL_free(bb);
        return 0;
    }
    *bb->readp = *bb->buf;
    bi->shutdown = 1;
    bi->init = 1;
    bi->num = -1;
    bi->ptr = (char *)bb;
    return 1;
}
static int mem_free(BIO *a)
{
    BIO_BUF_MEM *bb;

    if (a == NULL)
        return 0;

    bb = (BIO_BUF_MEM *)a->ptr;
    if (!mem_buf_free(a))
        return 0;
    OPENSSL_free(bb->readp);
    OPENSSL_free(bb);
    return 1;
}
static int mem_buf_free(BIO *a)
{
    if (a == NULL)
        return 0;

    if (a->shutdown && a->init && a->ptr != NULL) {
        BIO_BUF_MEM *bb = (BIO_BUF_MEM *)a->ptr;
        BUF_MEM *b = bb->buf;

        if (a->flags & BIO_FLAGS_MEM_RDONLY)
            b->data = NULL;
        BUF_MEM_free(b);
    }
    return 1;
}
static int mem_read(BIO *b, char *out, int outl)
{
    int ret = -1;
    BIO_BUF_MEM *bbm = (BIO_BUF_MEM *)b->ptr;
    BUF_MEM *bm = bbm->readp;

    if (b->flags & BIO_FLAGS_MEM_RDONLY)
        bm = bbm->buf;
    BIO_clear_retry_flags(b);
    ret = (outl >= 0 && (size_t)outl > bm->length) ? (int)bm->length : outl;
    if ((out != NULL) && (ret > 0)) {
        memcpy(out, bm->data, ret);
        bm->length -= ret;
        bm->max -= ret;
        bm->data += ret;
    } else if (bm->length == 0) {
        ret = b->num;
        if (ret != 0)
            BIO_set_retry_read(b);
    }
    return ret;
}
static int mem_write(BIO *b, const char *in, int inl)
{
    int ret = -1;
    int blen;
    BIO_BUF_MEM *bbm = (BIO_BUF_MEM *)b->ptr;

    if (in == NULL) {
        BIOerr(BIO_F_MEM_WRITE, BIO_R_NULL_PARAMETER);
        goto end;
    }
    if (b->flags & BIO_FLAGS_MEM_RDONLY) {
        BIOerr(BIO_F_MEM_WRITE, BIO_R_WRITE_TO_READ_ONLY_BIO);
        goto end;
    }
    BIO_clear_retry_flags(b);
    if (inl == 0)
        return 0;
    blen = bbm->readp->length;
    mem_buf_sync(b);
    if (BUF_MEM_grow_clean(bbm->buf, blen + inl) == 0)
        goto end;
    memcpy(bbm->buf->data + blen, in, inl);
    *bbm->readp = *bbm->buf;
    ret = inl;
 end:
    return ret;
}
