#include "los_seq_buf.h"
#include <stdlib.h>
int LosBufRelease(struct SeqBuf *seqBuf)
{
    if (seqBuf == NULL) {
        return -LOS_EPERM;
    }

    if (seqBuf->buf != NULL) {
        free(seqBuf->buf);
        seqBuf->buf = NULL;
    }
    free(seqBuf);

    return LOS_OK;
}
