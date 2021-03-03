#include <libopenmpt/libopenmpt.h>
#include <libopenmpt/libopenmpt_stream_callbacks_file.h>
#include <libopenmpt/libopenmpt_version.h>
#if !defined(OPENMPT_API_VERSION_MAKE)
#define OPENMPT_API_VERSION_MAKE(major, minor, patch) (((major)<<24)|((minor)<<16)|((patch)<<0))
#endif
#if !defined(OPENMPT_API_VERSION_AT_LEAST)
#define OPENMPT_API_VERSION_AT_LEAST(major, minor, patch) (OPENMPT_API_VERSION >= OPENMPT_API_VERSION_MAKE((major), (minor), (patch)))
#endif
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
typedef struct OpenMPTContext {
    const AVClass *class;
    openmpt_module *module;

    int channels;
    double duration;
    /* options */
    int sample_rate;
    int64_t layout;
    int subsong;
} OpenMPTContext;
#define OFFSET(x) offsetof(OpenMPTContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define D AV_OPT_FLAG_DECODING_PARAM
#define add_meta(s, name, meta)                    \
#if OPENMPT_API_VERSION_AT_LEAST(0,3,0)
#endif
#if OPENMPT_API_VERSION_AT_LEAST(0,3,0)
#else
#endif
#define AUDIO_PKT_SIZE 2048
#if OPENMPT_API_VERSION_AT_LEAST(0,3,0)
#endif
#if OPENMPT_API_VERSION_AT_LEAST(0,3,0)
#else
#endif
