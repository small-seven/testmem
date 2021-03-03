#include "libavutil/avassert.h"
#include "libavutil/audio_fifo.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "avfilter.h"
#include "audio.h"
#include "filters.h"
#include "internal.h"
#include "formats.h"
#include "window_func.h"
typedef struct AudioSurroundContext {
    const AVClass *class;

    char *out_channel_layout_str;
    char *in_channel_layout_str;

    float level_in;
    float level_out;
    float fc_in;
    float fc_out;
    float fl_in;
    float fl_out;
    float fr_in;
    float fr_out;
    float sl_in;
    float sl_out;
    float sr_in;
    float sr_out;
    float bl_in;
    float bl_out;
    float br_in;
    float br_out;
    float bc_in;
    float bc_out;
    float lfe_in;
    float lfe_out;
    int   lfe_mode;
    float angle;
    int   win_size;
    int   win_func;
    float overlap;

    float all_x;
    float all_y;

    float fc_x;
    float fl_x;
    float fr_x;
    float bl_x;
    float br_x;
    float sl_x;
    float sr_x;
    float bc_x;

    float fc_y;
    float fl_y;
    float fr_y;
    float bl_y;
    float br_y;
    float sl_y;
    float sr_y;
    float bc_y;

    float *input_levels;
    float *output_levels;
    int output_lfe;
    int lowcutf;
    int highcutf;

    float lowcut;
    float highcut;

    uint64_t out_channel_layout;
    uint64_t in_channel_layout;
    int nb_in_channels;
    int nb_out_channels;

    AVFrame *input;
    AVFrame *output;
    AVFrame *overlap_buffer;

    int buf_size;
    int hop_size;
    AVAudioFifo *fifo;
    RDFTContext **rdft, **irdft;
    float *window_func_lut;

    int64_t pts;
    int eof;

    void (*filter)(AVFilterContext *ctx);
    void (*upmix_stereo)(AVFilterContext *ctx,
                         float l_phase,
                         float r_phase,
                         float c_phase,
                         float mag_total,
                         float x, float y,
                         int n);
    void (*upmix_2_1)(AVFilterContext *ctx,
                      float l_phase,
                      float r_phase,
                      float c_phase,
                      float mag_total,
                      float lfe_im,
                      float lfe_re,
                      float x, float y,
                      int n);
    void (*upmix_3_0)(AVFilterContext *ctx,
                      float l_phase,
                      float r_phase,
                      float c_mag,
                      float c_phase,
                      float mag_total,
                      float x, float y,
                      int n);
    void (*upmix_5_0)(AVFilterContext *ctx,
                      float c_re, float c_im,
                      float mag_totall, float mag_totalr,
                      float fl_phase, float fr_phase,
                      float bl_phase, float br_phase,
                      float sl_phase, float sr_phase,
                      float xl, float yl,
                      float xr, float yr,
                      int n);
    void (*upmix_5_1)(AVFilterContext *ctx,
                      float c_re, float c_im,
                      float lfe_re, float lfe_im,
                      float mag_totall, float mag_totalr,
                      float fl_phase, float fr_phase,
                      float bl_phase, float br_phase,
                      float sl_phase, float sr_phase,
                      float xl, float yl,
                      float xr, float yr,
                      int n);
} AudioSurroundContext;
#define OFFSET(x) offsetof(AudioSurroundContext, x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
