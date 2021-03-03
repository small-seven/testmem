#include "libavutil/audio_fifo.h"
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "audio.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "hermite.h"
#include "internal.h"
typedef struct SidechainCompressContext {
    const AVClass *class;

    double level_in;
    double level_sc;
    double attack, attack_coeff;
    double release, release_coeff;
    double lin_slope;
    double ratio;
    double threshold;
    double makeup;
    double mix;
    double thres;
    double knee;
    double knee_start;
    double knee_stop;
    double lin_knee_start;
    double lin_knee_stop;
    double adj_knee_start;
    double adj_knee_stop;
    double compressed_knee_start;
    double compressed_knee_stop;
    int link;
    int detection;
    int mode;

    AVAudioFifo *fifo[2];
    int64_t pts;
} SidechainCompressContext;
#define OFFSET(x) offsetof(SidechainCompressContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM
#define sidechaincompress_options options
#define FAKE_INFINITY (65536.0 * 65536.0)
#define IS_FAKE_INFINITY(value) (fabs(value-FAKE_INFINITY) < 1.0)
#if CONFIG_SIDECHAINCOMPRESS_FILTER
#endif  /* CONFIG_SIDECHAINCOMPRESS_FILTER */
#if CONFIG_ACOMPRESSOR_FILTER
#define acompressor_options options
#endif  /* CONFIG_ACOMPRESSOR_FILTER */
