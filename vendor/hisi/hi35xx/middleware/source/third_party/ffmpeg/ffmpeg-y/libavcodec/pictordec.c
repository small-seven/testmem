#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "cga_data.h"
#include "internal.h"
typedef struct PicContext {
    int width, height;
    int nb_planes;
    GetByteContext g;
} PicContext;
static void picmemset(PicContext *s, AVFrame *frame, unsigned value, int run,
                      int *x, int *y, int *plane, int bits_per_plane)
{
    uint8_t *d;
    int shift = *plane * bits_per_plane;
    unsigned mask  = ((1U << bits_per_plane) - 1) << shift;
    int xl = *x;
    int yl = *y;
    int planel = *plane;
    value   <<= shift;

    d = frame->data[0] + yl * frame->linesize[0];
    while (run > 0) {
        int j;
        for (j = 8-bits_per_plane; j >= 0; j -= bits_per_plane) {
            d[xl] |= (value >> j) & mask;
            xl += 1;
            if (xl == s->width) {
                yl -= 1;
                xl = 0;
                if (yl < 0) {
                   yl = s->height - 1;
                   planel += 1;
                   if (planel >= s->nb_planes)
                       goto end;
                   value <<= bits_per_plane;
                   mask  <<= bits_per_plane;
                }
                d = frame->data[0] + yl * frame->linesize[0];
            }
        }
        run--;
    }
end:
    *x = xl;
    *y = yl;
    *plane = planel;
}
