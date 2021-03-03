#include "libavutil/pixdesc.h"
#include "libavutil/intreadwrite.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct Super2xSaIContext {
    /* masks used for two pixels interpolation */
    uint32_t hi_pixel_mask;
    uint32_t lo_pixel_mask;

    /* masks used for four pixels interpolation */
    uint32_t q_hi_pixel_mask;
    uint32_t q_lo_pixel_mask;

    int bpp; ///< bytes per pixel, pixel stride for each (packed) pixel
    int is_be;
} Super2xSaIContext;
#define GET_RESULT(A, B, C, D) ((A != C || A != D) - (B != C || B != D))
#define INTERPOLATE(A, B) (((A & hi_pixel_mask) >> 1) + ((B & hi_pixel_mask) >> 1) + (A & B & lo_pixel_mask))
#define Q_INTERPOLATE(A, B, C, D) ((A & q_hi_pixel_mask) >> 2) + ((B & q_hi_pixel_mask) >> 2) + ((C & q_hi_pixel_mask) >> 2) + ((D & q_hi_pixel_mask) >> 2) \
#define READ_COLOR4(dst, src_line, off) dst = *((const uint32_t *)src_line + off)
#define READ_COLOR3(dst, src_line, off) dst = AV_RL24 (src_line + 3*off)
#define READ_COLOR2(dst, src_line, off) dst = s->is_be ? AV_RB16(src_line + 2 * off) : AV_RL16(src_line + 2 * off)
