#include <math.h>
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/dict.h"
#include "libavutil/ffmath.h"
#include "libavutil/xga_font_data.h"
#include "libavutil/opt.h"
#include "libavutil/timestamp.h"
#include "libswresample/swresample.h"
#include "audio.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#define MAX_CHANNELS 63
#define PRE_B0  1.53512485958697
#define PRE_B1 -2.69169618940638
#define PRE_B2  1.19839281085285
#define PRE_A1 -1.69065929318241
#define PRE_A2  0.73248077421585
#define RLB_B0  1.0
#define RLB_B1 -2.0
#define RLB_B2  1.0
#define RLB_A1 -1.99004745483398
#define RLB_A2  0.99007225036621
#define ABS_THRES    -70            ///< silence gate: we discard anything below this absolute (LUFS) threshold
#define ABS_UP_THRES  10            ///< upper loud limit to consider (ABS_THRES being the minimum)
#define HIST_GRAIN   100            ///< defines histogram precision
#define HIST_SIZE  ((ABS_UP_THRES - ABS_THRES) * HIST_GRAIN + 1)
typedef struct EBUR128Context {
    const AVClass *class;           ///< AVClass context for log and options purpose

    /* peak metering */
    int peak_mode;                  ///< enabled peak modes
    double *true_peaks;             ///< true peaks per channel
    double *sample_peaks;           ///< sample peaks per channel
    double *true_peaks_per_frame;   ///< true peaks in a frame per channel
#if CONFIG_SWRESAMPLE
    SwrContext *swr_ctx;            ///< over-sampling context for true peak metering
    double *swr_buf;                ///< resampled audio data for true peak metering
    int swr_linesize;
#endif

    /* video  */
    int do_video;                   ///< 1 if video output enabled, 0 otherwise
    int w, h;                       ///< size of the video output
    struct rect text;               ///< rectangle for the LU legend on the left
    struct rect graph;              ///< rectangle for the main graph in the center
    struct rect gauge;              ///< rectangle for the gauge on the right
    AVFrame *outpicref;             ///< output picture reference, updated regularly
    int meter;                      ///< select a EBU mode between +9 and +18
    int scale_range;                ///< the range of LU values according to the meter
    int y_zero_lu;                  ///< the y value (pixel position) for 0 LU
    int y_opt_max;                  ///< the y value (pixel position) for 1 LU
    int y_opt_min;                  ///< the y value (pixel position) for -1 LU
    int *y_line_ref;                ///< y reference values for drawing the LU lines in the graph and the gauge

    /* audio */
    int nb_channels;                ///< number of channels in the input
    double *ch_weighting;           ///< channel weighting mapping
    int sample_count;               ///< sample count used for refresh frequency, reset at refresh

    /* Filter caches.
     * The mult by 3 in the following is for X[i], X[i-1] and X[i-2] */
    double x[MAX_CHANNELS * 3];     ///< 3 input samples cache for each channel
    double y[MAX_CHANNELS * 3];     ///< 3 pre-filter samples cache for each channel
    double z[MAX_CHANNELS * 3];     ///< 3 RLB-filter samples cache for each channel

#define I400_BINS  (48000 * 4 / 10)
#define I3000_BINS (48000 * 3)
    struct integrator i400;         ///< 400ms integrator, used for Momentary loudness  (M), and Integrated loudness (I)
    struct integrator i3000;        ///<    3s integrator, used for Short term loudness (S), and Loudness Range      (LRA)

    /* I and LRA specific */
    double integrated_loudness;     ///< integrated loudness in LUFS (I)
    double loudness_range;          ///< loudness range in LU (LRA)
    double lra_low, lra_high;       ///< low and high LRA values

    /* misc */
    int loglevel;                   ///< log level for frame logging
    int metadata;                   ///< whether or not to inject loudness results in frames
    int dual_mono;                  ///< whether or not to treat single channel input files as dual-mono
    double pan_law;                 ///< pan law value used to calculate dual-mono measurements
    int target;                     ///< target level in LUFS used to set relative zero LU in visualization
    int gauge_type;                 ///< whether gauge shows momentary or short
    int scale;                      ///< display scale type of statistics
} EBUR128Context;
#define OFFSET(x) offsetof(EBUR128Context, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define V AV_OPT_FLAG_VIDEO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM
#define FONT8   0
#define FONT16  1
#define PAD 8
#define DRAW_RECT(r) do { \
#define BACK_MASK (AV_CH_BACK_LEFT    |AV_CH_BACK_CENTER    |AV_CH_BACK_RIGHT| \
#if CONFIG_SWRESAMPLE
#endif
#define ENERGY(loudness) (ff_exp10(((loudness) + 0.691) / 10.))
#define LOUDNESS(energy) (-0.691 + 10 * log10(energy))
#define DBFS(energy) (20 * log10(energy))
#define HIST_POS(power) (int)(((power) - ABS_THRES) * HIST_GRAIN)
#if CONFIG_SWRESAMPLE
#endif
#define MOVE_TO_NEXT_CACHED_ENTRY(time) do {                \
#define FILTER(Y, X, name) do {                                                 \
#define COMPUTE_LOUDNESS(m, time) do {                                              \
#define I_GATE_THRES -10  // initially defined to -8 LU in the first EBU standard
#define LRA_GATE_THRES -20
#define LRA_LOWER_PRC   10
#define LRA_HIGHER_PRC  95
#define LOG_FMT "TARGET:%d LUFS    M:%6.1f S:%6.1f     I:%6.1f %s       LRA:%6.1f LU"
#define META_PREFIX "lavfi.r128."
#define SET_META(name, var) do {                                            \
#define SET_META_PEAK(name, ptype) do {                                     \
#define PRINT_PEAKS(str, sp, ptype) do {                            \
#define PRINT_PEAK_SUMMARY(str, sp, ptype) do {                  \
#if CONFIG_SWRESAMPLE
#endif
