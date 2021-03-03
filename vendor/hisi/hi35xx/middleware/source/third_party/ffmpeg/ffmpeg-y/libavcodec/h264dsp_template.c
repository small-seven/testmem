#include "bit_depth_template.c"
#define op_scale1(x)  block[x] = av_clip_pixel( (block[x]*weight + offset) >> log2_denom )
#define op_scale2(x)  dst[x] = av_clip_pixel( (src[x]*weights + dst[x]*weightd + offset) >> (log2_denom+1))
#define H264_WEIGHT(W) \
#undef op_scale1
#undef op_scale2
#undef H264_WEIGHT
