#include <float.h>
#include "libavutil/common.h"
#include "libavutil/float_dsp.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/xga_font_data.h"
#include "libavcodec/avfft.h"
#include "audio.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "internal.h"
#include "af_afir.h"
#define AF AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define VF AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define OFFSET(x) offsetof(AudioFIRContext, x)
