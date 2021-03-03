#include "a64colors.h"
#include "a64tables.h"
#include "elbg.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#define DITHERSTEPS   8
#define CHARSET_CHARS 256
#define INTERLACED    1
#define CROP_SCREENS  1
#define C64XRES 320
#define C64YRES 200
typedef struct A64Context {
    /* variables for multicolor modes */
    AVLFG randctx;
    int mc_lifetime;
    int mc_use_5col;
    unsigned mc_frame_counter;
    int *mc_meta_charset;
    int *mc_charmap;
    int *mc_best_cb;
    int mc_luma_vals[5];
    uint8_t *mc_charset;
    uint8_t *mc_colram;
    uint8_t *mc_palette;
    int mc_pal_size;

    /* pts of the next packet that will be output */
    int64_t next_pts;
} A64Context;
#if CONFIG_A64MULTI_ENCODER
#endif
#if CONFIG_A64MULTI5_ENCODER
#endif
