#include "swscale_internal.h"
typedef struct VScalerContext
{
    uint16_t *filter[2];
    int32_t  *filter_pos;
    int filter_size;
    int isMMX;
    void *pfn;
    yuv2packedX_fn yuv2packedX;
} VScalerContext;
