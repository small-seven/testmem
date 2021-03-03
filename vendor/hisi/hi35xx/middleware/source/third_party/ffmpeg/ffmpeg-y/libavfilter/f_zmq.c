#include <zmq.h>
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
#include "video.h"
typedef struct ZMQContext {
    const AVClass *class;
    void *zmq;
    void *responder;
    char *bind_address;
    int command_count;
} ZMQContext;
#define OFFSET(x) offsetof(ZMQContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_VIDEO_PARAM
typedef struct Command {
    char *target, *command, *arg;
} Command;
#define SPACES " \f\t\n\r"
#if CONFIG_ZMQ_FILTER
#define zmq_options options
#endif
#if CONFIG_AZMQ_FILTER
#define azmq_options options
#endif
