#include <bcm_host.h>
#include <interface/mmal/mmal.h>
#include <interface/mmal/mmal_parameters_video.h>
#include <interface/mmal/util/mmal_util.h>
#include <interface/mmal/util/mmal_util_params.h>
#include <interface/mmal/util/mmal_default_components.h>
#include <interface/mmal/vc/mmal_vc_api.h>
#include <stdatomic.h>
#include "avcodec.h"
#include "hwaccel.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libavutil/buffer.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/log.h"
typedef struct FFBufferEntry {
    AVBufferRef *ref;
    void *data;
    size_t length;
    int64_t pts, dts;
    int flags;
    struct FFBufferEntry *next;
} FFBufferEntry;
typedef struct FFPoolRef {
    atomic_int refcount;
    MMAL_POOL_T *pool;
} FFPoolRef;
typedef struct FFBufferRef {
    MMAL_BUFFER_HEADER_T *buffer;
    FFPoolRef *pool;
} FFBufferRef;
typedef struct MMALDecodeContext {
    AVClass *av_class;
    int extra_buffers;
    int extra_decoder_buffers;

    MMAL_COMPONENT_T *decoder;
    MMAL_QUEUE_T *queue_decoded_frames;
    MMAL_POOL_T *pool_in;
    FFPoolRef *pool_out;

    // Waiting input packets. Because the libavcodec API requires decoding and
    // returning packets in lockstep, it can happen that queue_decoded_frames
    // contains almost all surfaces - then the decoder input queue can quickly
    // fill up and won't accept new input either. Without consuming input, the
    // libavcodec API can't return new frames, and we have a logical deadlock.
    // This is avoided by queuing such buffers here.
    FFBufferEntry *waiting_buffers, *waiting_buffers_tail;

    int64_t packets_sent;
    atomic_int packets_buffered;
    int64_t frames_output;
    int eos_received;
    int eos_sent;
    int extradata_sent;
    int interlaced_frame;
    int top_field_first;
} MMALDecodeContext;
#define MAX_DELAYED_FRAMES 16
#if HAVE_MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS
#endif
#if FF_API_PKT_PTS
#endif
#define FFMMAL_DEC_CLASS(NAME) \
#define FFMMAL_DEC(NAME, ID) \
