#include <float.h>
#include "libavcodec/avfft.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "libavutil/samplefmt.h"
#include "avfilter.h"
#include "audio.h"
#include "internal.h"
typedef struct AudioFragment {
    // index of the first sample of this fragment in the overall waveform;
    // 0: input sample position
    // 1: output sample position
    int64_t position[2];

    // original packed multi-channel samples:
    uint8_t *data;

    // number of samples in this fragment:
    int nsamples;

    // rDFT transform of the down-mixed mono fragment, used for
    // fast waveform alignment via correlation in frequency domain:
    FFTSample *xdat;
} AudioFragment;
typedef enum {
    YAE_LOAD_FRAGMENT,
    YAE_ADJUST_POSITION,
    YAE_RELOAD_FRAGMENT,
    YAE_OUTPUT_OVERLAP_ADD,
    YAE_FLUSH_OUTPUT,
} FilterState;
typedef struct ATempoContext {
    const AVClass *class;

    // ring-buffer of input samples, necessary because some times
    // input fragment position may be adjusted backwards:
    uint8_t *buffer;

    // ring-buffer maximum capacity, expressed in sample rate time base:
    int ring;

    // ring-buffer house keeping:
    int size;
    int head;
    int tail;

    // 0: input sample position corresponding to the ring buffer tail
    // 1: output sample position
    int64_t position[2];

    // first input timestamp, all other timestamps are offset by this one
    int64_t start_pts;

    // sample format:
    enum AVSampleFormat format;

    // number of channels:
    int channels;

    // row of bytes to skip from one sample to next, across multple channels;
    // stride = (number-of-channels * bits-per-sample-per-channel) / 8
    int stride;

    // fragment window size, power-of-two integer:
    int window;

    // Hann window coefficients, for feathering
    // (blending) the overlapping fragment region:
    float *hann;

    // tempo scaling factor:
    double tempo;

    // a snapshot of previous fragment input and output position values
    // captured when the tempo scale factor was set most recently:
    int64_t origin[2];

    // current/previous fragment ring-buffer:
    AudioFragment frag[2];

    // current fragment index:
    uint64_t nfrag;

    // current state:
    FilterState state;

    // for fast correlation calculation in frequency domain:
    RDFTContext *real_to_complex;
    RDFTContext *complex_to_real;
    FFTSample *correlation;

    // for managing AVFilterPad.request_frame and AVFilterPad.filter_frame
    AVFrame *dst_buffer;
    uint8_t *dst;
    uint8_t *dst_end;
    uint64_t nsamples_in;
    uint64_t nsamples_out;
} ATempoContext;
#define YAE_ATEMPO_MIN 0.5
#define YAE_ATEMPO_MAX 100.0
#define OFFSET(x) offsetof(ATempoContext, x)
#define RE_MALLOC_OR_FAIL(field, field_size)                    \
#define yae_init_xdat(scalar_type, scalar_max)                          \
#define yae_blend(scalar_type)                                          \
