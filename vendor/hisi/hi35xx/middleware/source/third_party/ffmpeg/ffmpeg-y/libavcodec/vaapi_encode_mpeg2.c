#include <va/va.h>
#include <va/va_enc_mpeg2.h>
#include "libavutil/avassert.h"
#include "avcodec.h"
#include "cbs.h"
#include "cbs_mpeg2.h"
#include "mpeg12.h"
#include "vaapi_encode.h"
typedef struct VAAPIEncodeMPEG2Context {
    VAAPIEncodeContext common;

    // User options.
    int profile;
    int level;

    // Derived settings.
    int quant_i;
    int quant_p;
    int quant_b;

    unsigned int bit_rate;
    unsigned int vbv_buffer_size;

    AVRational frame_rate;

    unsigned int f_code_horizontal;
    unsigned int f_code_vertical;

    // Stream state.
    int64_t last_i_frame;

    // Writer structures.
    MPEG2RawSequenceHeader sequence_header;
    MPEG2RawExtensionData  sequence_extension;
    MPEG2RawExtensionData  sequence_display_extension;
    MPEG2RawGroupOfPicturesHeader gop_header;
    MPEG2RawPictureHeader  picture_header;
    MPEG2RawExtensionData  picture_coding_extension;

    CodedBitstreamContext *cbc;
    CodedBitstreamFragment current_fragment;
} VAAPIEncodeMPEG2Context;
#define OFFSET(x) offsetof(VAAPIEncodeMPEG2Context, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM)
#define PROFILE(name, value)  name, NULL, 0, AV_OPT_TYPE_CONST, \
#undef PROFILE
#define LEVEL(name, value) name, NULL, 0, AV_OPT_TYPE_CONST, \
#undef LEVEL
