#include <stdint.h>
#include "libavutil/mathematics.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "avresample.h"
#include "internal.h"
#include "audio_mix.h"
#define OFFSET(x) offsetof(AVAudioResampleContext, x)
#define PARAM AV_OPT_FLAG_AUDIO_PARAM
