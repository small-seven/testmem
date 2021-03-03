#include "libavutil/opt.h"
#include "swresample_internal.h"
#include <float.h>
#define  C30DB  M_SQRT2
#define  C15DB  1.189207115
#define C__0DB  1.0
#define C_15DB  0.840896415
#define C_30DB  M_SQRT1_2
#define C_45DB  0.594603558
#define C_60DB  0.5
#define OFFSET(x) offsetof(SwrContext,x)
#define PARAM AV_OPT_FLAG_AUDIO_PARAM
