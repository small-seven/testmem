#include "swresample_internal.h"
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#define TEMPLATE_REMATRIX_FLT
#include "rematrix_template.c"
#undef TEMPLATE_REMATRIX_FLT
#define TEMPLATE_REMATRIX_DBL
#include "rematrix_template.c"
#undef TEMPLATE_REMATRIX_DBL
#define TEMPLATE_REMATRIX_S16
#include "rematrix_template.c"
#define TEMPLATE_CLIP
#include "rematrix_template.c"
#undef TEMPLATE_CLIP
#undef TEMPLATE_REMATRIX_S16
#define TEMPLATE_REMATRIX_S32
#include "rematrix_template.c"
#undef TEMPLATE_REMATRIX_S32
#define FRONT_LEFT             0
#define FRONT_RIGHT            1
#define FRONT_CENTER           2
#define LOW_FREQUENCY          3
#define BACK_LEFT              4
#define BACK_RIGHT             5
#define FRONT_LEFT_OF_CENTER   6
#define FRONT_RIGHT_OF_CENTER  7
#define BACK_CENTER            8
#define SIDE_LEFT              9
#define SIDE_RIGHT             10
#define TOP_CENTER             11
#define TOP_FRONT_LEFT         12
#define TOP_FRONT_CENTER       13
#define TOP_FRONT_RIGHT        14
#define TOP_BACK_LEFT          15
#define TOP_BACK_CENTER        16
#define TOP_BACK_RIGHT         17
#define NUM_NAMED_CHANNELS     18
