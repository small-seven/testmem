#include "libavutil/attributes.h"
#include "libavutil/audio_fifo.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/float_dsp.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "audio.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "internal.h"
#define INPUT_ON       1    /**< input is active */
#define INPUT_EOF      2    /**< input has reached EOF (may still be active) */
#define DURATION_LONGEST  0
#define DURATION_SHORTEST 1
#define DURATION_FIRST    2
typedef struct FrameInfo {
    int nb_samples;
    int64_t pts;
    struct FrameInfo *next;
} FrameInfo;
typedef struct FrameList {
    int nb_frames;
    int nb_samples;
    FrameInfo *list;
    FrameInfo *end;
} FrameList;
typedef struct MixContext {
    const AVClass *class;       /**< class for AVOptions */
    AVFloatDSPContext *fdsp;

    int nb_inputs;              /**< number of inputs */
    int active_inputs;          /**< number of input currently active */
    int duration_mode;          /**< mode for determining duration */
    float dropout_transition;   /**< transition time when an input drops out */
    char *weights_str;          /**< string for custom weights for every input */

    int nb_channels;            /**< number of channels */
    int sample_rate;            /**< sample rate */
    int planar;
    AVAudioFifo **fifos;        /**< audio fifo for each input */
    uint8_t *input_state;       /**< current state of each input */
    float *input_scale;         /**< mixing scale factor for each input */
    float *weights;             /**< custom weights for every input */
    float weight_sum;           /**< sum of custom weights for every input */
    float *scale_norm;          /**< normalization factor for every input */
    int64_t next_pts;           /**< calculated pts for next output frame */
    FrameList *frame_list;      /**< list of frame info for the first input */
} MixContext;
#define OFFSET(x) offsetof(MixContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM
