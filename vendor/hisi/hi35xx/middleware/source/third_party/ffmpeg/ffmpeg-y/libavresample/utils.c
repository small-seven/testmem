#include "libavutil/common.h"
#include "libavutil/dict.h"
#include "libavutil/frame.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "avresample.h"
#include "internal.h"
#include "audio_data.h"
#include "audio_convert.h"
#include "audio_mix.h"
#include "resample.h"
#ifdef DEBUG
#endif
void avresample_free(AVAudioResampleContext **avr)
{
    if (!*avr)
        return;
    avresample_close(*avr);
    av_opt_free(*avr);
    av_freep(avr);
}
#define LICENSE_PREFIX "libavresample license: "
