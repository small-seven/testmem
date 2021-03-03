#include <opus.h>
#include <opus_multistream.h>
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/ffmath.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "vorbis.h"
#include "mathops.h"
#include "libopus.h"
#ifndef OPUS_SET_GAIN
#endif
#ifdef OPUS_SET_PHASE_INVERSION_DISABLED_REQUEST
#endif
#define OPUS_HEAD_SIZE 19
#ifdef OPUS_SET_GAIN
#else
#endif
#ifdef OPUS_SET_PHASE_INVERSION_DISABLED_REQUEST
#endif
#define MAX_FRAME_SIZE (960 * 6)
#ifndef OPUS_SET_GAIN
#endif
#define OFFSET(x) offsetof(struct libopus_context, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_DECODING_PARAM
#ifdef OPUS_SET_PHASE_INVERSION_DISABLED_REQUEST
#endif
