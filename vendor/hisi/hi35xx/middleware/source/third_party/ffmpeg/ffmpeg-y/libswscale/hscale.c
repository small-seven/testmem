#include "swscale_internal.h"
typedef struct FilterContext
{
    uint16_t *filter;
    int *filter_pos;
    int filter_size;
    int xInc;
} FilterContext;
typedef struct ColorContext
{
    uint32_t *pal;
} ColorContext;
