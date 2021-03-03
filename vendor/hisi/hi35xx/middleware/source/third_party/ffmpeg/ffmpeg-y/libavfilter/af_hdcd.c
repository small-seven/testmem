#include "libavutil/opt.h"
#include "libavutil/avassert.h"
#include "avfilter.h"
#include "internal.h"
#include "audio.h"
#define PEAK_EXT_LEVEL 0x5981 /* + sizeof(peaktab)-1 = 0x8000  */
#define HDCD_PROCESS_STEREO_DEFAULT 1
#define HDCD_MAX_CHANNELS 2
#define GAINTOFLOAT(g) (g) ? -(float)(g>>1) - ((g & 1) ? 0.5 : 0.0) : 0.0
#define APPLY_GAIN(s,g) do{int64_t s64 = s; s64 *= gaintab[g]; s = (int32_t)(s64 >> 23); }while(0);
#define TONEGEN16(sn, f, sr, a) (int16_t)(sin((6.28318530718 * (sn) * (f)) /(sr)) * (a) * 0x7fff)
typedef struct hdcd_state {
    uint64_t window;
    unsigned char readahead;

    /** arg is set when a packet prefix is found.
     *  control is the active control code, where
     *  bit 0-3: target_gain, 4-bit (3.1) fixed-point value
     *  bit 4  : peak_extend
     *  bit 5  : transient_filter
     *  bit 6,7: always zero */
    uint8_t arg, control;
    unsigned int sustain, sustain_reset; /**< code detect timer */

    int running_gain; /**< 11-bit (3.8) fixed point, extended from target_gain */

    /* counters */
    int code_counterA;            /**< 8-bit format packet */
    int code_counterA_almost;     /**< looks like an A code, but a bit expected to be 0 is 1 */
    int code_counterB;            /**< 16-bit format packet, 8-bit code, 8-bit XOR of code */
    int code_counterB_checkfails; /**< looks like a B code, but doesn't pass the XOR check */
    int code_counterC;            /**< packet prefix was found, expect a code */
    int code_counterC_unmatched;  /**< told to look for a code, but didn't find one */
    int count_peak_extend;        /**< valid packets where peak_extend was enabled */
    int count_transient_filter;   /**< valid packets where filter was detected */
    /** target_gain is a 4-bit (3.1) fixed-point value, always
     *  negative, but stored positive.
     *  The 16 possible values range from -7.5 to 0.0 dB in
     *  steps of 0.5, but no value below -6.0 dB should appear. */
    int gain_counts[16];
    int max_gain;
    /** occurrences of code detect timer expiring without detecting
     *  a code. -1 for timer never set. */
    int count_sustain_expired;

    int rate;                   /**< sampling rate */
    int _ana_snb;               /**< used in the analyze mode tone generator */
} hdcd_state;
typedef enum {
    HDCD_PE_NEVER        = 0, /**< All valid packets have PE set to off */
    HDCD_PE_INTERMITTENT = 1, /**< Some valid packets have PE set to on */
    HDCD_PE_PERMANENT    = 2, /**< All valid packets have PE set to on  */
} hdcd_pe;
typedef enum {
    HDCD_NONE            = 0,  /**< HDCD packets do not (yet) appear  */
    HDCD_NO_EFFECT       = 1,  /**< HDCD packets appear, but all control codes are NOP */
    HDCD_EFFECTUAL       = 2,  /**< HDCD packets appear, and change the output in some way */
} hdcd_dv;
typedef enum {
    HDCD_PVER_NONE       = 0, /**< No packets (yet) discovered */
    HDCD_PVER_A          = 1, /**< Packets of type A (8-bit control) discovered */
    HDCD_PVER_B          = 2, /**< Packets of type B (8-bit control, 8-bit XOR) discovered */
    HDCD_PVER_MIX        = 3, /**< Packets of type A and B discovered, most likely an encoding error */
} hdcd_pf;
typedef struct hdcd_detection_data {
    hdcd_dv hdcd_detected;
    hdcd_pf packet_type;
    int total_packets;         /**< valid packets */
    int errors;                /**< detectable errors */
    hdcd_pe peak_extend;
    int uses_transient_filter;
    float max_gain_adjustment; /**< in dB, expected in the range -7.5 to 0.0 */
    int cdt_expirations;       /**< -1 for never set, 0 for set but never expired */

    int _active_count;         /**< used internally */
} hdcd_detection_data;
typedef enum {
    HDCD_ANA_OFF    = 0,
    HDCD_ANA_LLE    = 1,
    HDCD_ANA_PE     = 2,
    HDCD_ANA_CDT    = 3,
    HDCD_ANA_TGM    = 4,
    HDCD_ANA_TOP    = 5, /**< used in max value of AVOption */
} hdcd_ana_mode;
#define HDCD_ANA_OFF_DESC "disabled"
#define HDCD_ANA_LLE_DESC "gain adjustment level at each sample"
#define HDCD_ANA_PE_DESC  "samples where peak extend occurs"
#define HDCD_ANA_CDT_DESC "samples where the code detect timer is active"
#define HDCD_ANA_TGM_DESC "samples where the target gain does not match between channels"
typedef struct HDCDContext {
    const AVClass *class;
    hdcd_state state[HDCD_MAX_CHANNELS];

    /* AVOption members */
    /** use hdcd_*_stereo() functions to process both channels together.
     *  -af hdcd=process_stereo=0 for off
     *  -af hdcd=process_stereo=1 for on
     *  default is HDCD_PROCESS_STEREO_DEFAULT */
    int process_stereo;
    /** always extend peaks above -3dBFS even if PE isn't signaled
     *  -af hdcd=force_pe=0 for off
     *  -af hdcd=force_pe=1 for on
     *  default is off */
    int force_pe;

    /** analyze mode replaces the audio with a solid tone and adjusts
     *  the amplitude to signal some specific aspect of the decoding
     *  process. See docs or HDCD_ANA_* defines. */
    int analyze_mode;

    int cdt_ms;               /**< code detect timer period in ms */

    int disable_autoconvert;  /**< disable any format conversion or resampling in the filter graph */

    int bits_per_sample;      /**< bits per sample 16, 20, or 24 */
    /* end AVOption members */

    /** config_input() and config_output() scan links for any resampling
     *  or format changes. If found, warnings are issued and bad_config
     *  is set. */
    int bad_config;

    AVFilterContext *fctx; /**< filter context for logging errors */
    int sample_count;      /**< used in error logging */
    int val_target_gain;   /**< last matching target_gain in both channels */

    /* User information/stats */
    hdcd_detection_data detect;
} HDCDContext;
#define OFFSET(x) offsetof(HDCDContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
typedef enum {
    HDCD_OK=0,
    HDCD_TG_MISMATCH
} hdcd_control_result;
