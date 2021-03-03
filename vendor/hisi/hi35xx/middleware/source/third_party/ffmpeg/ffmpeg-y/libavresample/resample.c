#include "libavutil/common.h"
#include "libavutil/libm.h"
#include "libavutil/log.h"
#include "internal.h"
#include "resample.h"
#include "audio_data.h"
#define CONFIG_RESAMPLE_DBL
#include "resample_template.c"
#undef CONFIG_RESAMPLE_DBL
#define CONFIG_RESAMPLE_FLT
#include "resample_template.c"
#undef CONFIG_RESAMPLE_FLT
#define CONFIG_RESAMPLE_S32
#include "resample_template.c"
#undef CONFIG_RESAMPLE_S32
#include "resample_template.c"
void ff_audio_resample_free(ResampleContext **c)
{
    if (!*c)
        return;
    ff_audio_data_free(&(*c)->buffer);
    av_free((*c)->filter_bank);
    av_freep(c);
}
