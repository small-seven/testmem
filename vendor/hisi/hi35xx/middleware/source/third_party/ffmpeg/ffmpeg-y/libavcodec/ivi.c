#include <inttypes.h>
#include "libavutil/attributes.h"
#include "libavutil/imgutils.h"
#include "libavutil/timer.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#include "mathops.h"
#include "ivi.h"
#include "ivi_dsp.h"
typedef void (*ivi_mc_func) (int16_t *buf, const int16_t *ref_buf,
                             ptrdiff_t pitch, int mc_type);
typedef void (*ivi_mc_avg_func) (int16_t *buf, const int16_t *ref_buf1,
                                 const int16_t *ref_buf2,
                                 ptrdiff_t pitch, int mc_type, int mc_type2);

static int ivi_mc(const IVIBandDesc *band, ivi_mc_func mc, ivi_mc_avg_func mc_avg,
                  int offs, int mv_x, int mv_y, int mv_x2, int mv_y2,
                  int mc_type, int mc_type2)
{
    int ref_offs = offs + mv_y * band->pitch + mv_x;
    int buf_size = band->pitch * band->aheight;
    int min_size = band->pitch * (band->blk_size - 1) + band->blk_size;
    int ref_size = (mc_type > 1) * band->pitch + (mc_type & 1);

    if (mc_type != -1) {
        av_assert0(offs >= 0 && ref_offs >= 0 && band->ref_buf);
        av_assert0(buf_size - min_size >= offs);
        av_assert0(buf_size - min_size - ref_size >= ref_offs);
    }
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
