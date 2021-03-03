#include <va/va.h>
#include <va/va_dec_hevc.h>
#include "avcodec.h"
#include "hevcdec.h"
#include "hwaccel.h"
#include "vaapi_decode.h"
typedef struct VAAPIDecodePictureHEVC {
    VAPictureParameterBufferHEVC pic_param;
    VASliceParameterBufferHEVC last_slice_param;
    const uint8_t *last_buffer;
    size_t         last_size;

    VAAPIDecodePicture pic;
} VAAPIDecodePictureHEVC;
