#include <stdbool.h>
#include "avcodec.h"
#include "internal.h"
#include "libavutil/intreadwrite.h"
#include "sbc.h"
#include "sbcdec_data.h"
typedef struct SBCDecContext {
    AVClass *class;
    DECLARE_ALIGNED(SBC_ALIGN, struct sbc_frame, frame);
    DECLARE_ALIGNED(SBC_ALIGN, struct sbc_decoder_state, dsp);
} SBCDecContext;
