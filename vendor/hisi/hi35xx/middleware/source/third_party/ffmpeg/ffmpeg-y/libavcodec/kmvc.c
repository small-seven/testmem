#include <stdio.h>
#include <stdlib.h>
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "libavutil/common.h"
#define KMVC_KEYFRAME 0x80
#define KMVC_PALETTE  0x40
#define KMVC_METHOD   0x0F
#define MAX_PALSIZE   256
typedef struct KmvcContext {
    AVCodecContext *avctx;

    int setpal;
    int palsize;
    uint32_t pal[MAX_PALSIZE];
    uint8_t *cur, *prev;
    uint8_t frm0[320 * 200], frm1[320 * 200];
    GetByteContext g;
} KmvcContext;
typedef struct BitBuf {
    int bits;
    int bitbuf;
} BitBuf;
#define BLK(data, x, y)  data[av_clip((x) + (y) * 320, 0, 320 * 200 -1)]
#define kmvc_init_getbits(bb, g)  bb.bits = 7; bb.bitbuf = bytestream2_get_byte(g);
#define kmvc_getbit(bb, g, res) {\
