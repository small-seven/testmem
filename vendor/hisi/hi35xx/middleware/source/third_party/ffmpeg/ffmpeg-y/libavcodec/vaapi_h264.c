#include "h264dec.h"
#include "h264_ps.h"
#include "hwaccel.h"
#include "vaapi_decode.h"
typedef struct DPB {
    int            size;        ///< Current number of reference frames in the DPB
    int            max_size;    ///< Max number of reference frames. This is FF_ARRAY_ELEMS(VAPictureParameterBufferH264.ReferenceFrames)
    VAPictureH264 *va_pics;     ///< Pointer to VAPictureParameterBufferH264.ReferenceFrames array
} DPB;
