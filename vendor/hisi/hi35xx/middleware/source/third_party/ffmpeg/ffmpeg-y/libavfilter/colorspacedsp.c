#include "colorspacedsp.h"
#define SS_W 0
#define SS_H 0
#define BIT_DEPTH 8
#include "colorspacedsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "colorspacedsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 12
#include "colorspacedsp_template.c"
#undef SS_W
#undef SS_H
#define SS_W 1
#define SS_H 0
#undef BIT_DEPTH
#define BIT_DEPTH 8
#include "colorspacedsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "colorspacedsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 12
#include "colorspacedsp_template.c"
#undef SS_W
#undef SS_H
#define SS_W 1
#define SS_H 1
#undef BIT_DEPTH
#define BIT_DEPTH 8
#include "colorspacedsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "colorspacedsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 12
#include "colorspacedsp_template.c"
#define init_yuv2rgb_fn(bit) \
#define init_rgb2yuv_fn(bit) \
#define init_rgb2yuv_fsb_fn(bit) \
#define init_yuv2yuv_fn(idx1, bit1, bit2) \
#define init_yuv2yuv_fns(bit1) \
