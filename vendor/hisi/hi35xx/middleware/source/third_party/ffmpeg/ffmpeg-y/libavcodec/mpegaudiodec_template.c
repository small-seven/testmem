#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/float_dsp.h"
#include "libavutil/libm.h"
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#include "mathops.h"
#include "mpegaudiodsp.h"
#include "mpegaudio.h"
#include "mpegaudiodecheader.h"
#define BACKSTEP_SIZE 512
#define EXTRABYTES 24
#define LAST_BUF_SIZE 2 * BACKSTEP_SIZE + EXTRABYTES
typedef struct GranuleDef {
    uint8_t scfsi;
    int part2_3_length;
    int big_values;
    int global_gain;
    int scalefac_compress;
    uint8_t block_type;
    uint8_t switch_point;
    int table_select[3];
    int subblock_gain[3];
    uint8_t scalefac_scale;
    uint8_t count1table_select;
    int region_size[3]; /* number of huffman codes in each region */
    int preflag;
    int short_start, long_end; /* long/short band indexes */
    uint8_t scale_factors[40];
    DECLARE_ALIGNED(16, INTFLOAT, sb_hybrid)[SBLIMIT * 18]; /* 576 samples */
} GranuleDef;
typedef struct MPADecodeContext {
    MPA_DECODE_HEADER
    uint8_t last_buf[LAST_BUF_SIZE];
    int last_buf_size;
    int extrasize;
    /* next header (used in free format parsing) */
    uint32_t free_format_next_header;
    GetBitContext gb;
    GetBitContext in_gb;
    DECLARE_ALIGNED(32, MPA_INT, synth_buf)[MPA_MAX_CHANNELS][512 * 2];
    int synth_buf_offset[MPA_MAX_CHANNELS];
    DECLARE_ALIGNED(32, INTFLOAT, sb_samples)[MPA_MAX_CHANNELS][36][SBLIMIT];
    INTFLOAT mdct_buf[MPA_MAX_CHANNELS][SBLIMIT * 18]; /* previous samples, for layer 3 MDCT */
    GranuleDef granules[2][2]; /* Used in Layer 3 */
    int adu_mode; ///< 0 for standard mp3, 1 for adu formatted mp3
    int dither_state;
    int err_recognition;
    AVCodecContext* avctx;
    MPADSPContext mpadsp;
    AVFloatDSPContext *fdsp;
    AVFrame *frame;
} MPADecodeContext;
#define HEADER_SIZE 4
#include "mpegaudiodata.h"
#include "mpegaudiodectab.h"
#include "mpegaudio_tablegen.h"
#define SCALE_GEN(v) \
#ifdef DEBUG
#endif
#if !USE_FLOATS
#else
#endif
#if USE_FLOATS
#endif
#if USE_FLOATS
#endif
#define C3 FIXHR(0.86602540378443864676/2)
#define C4 FIXHR(0.70710678118654752439/2) //0.5 / cos(pi*(9)/36)
#define C5 FIXHR(0.51763809020504152469/2) //0.5 / cos(pi*(5)/36)
#define C6 FIXHR(1.93185165257813657349/4) //0.5 / cos(pi*(15)/36)
#define SPLIT(dst,sf,n)             \
#if USE_FLOATS
#define READ_FLIP_SIGN(dst,src)                     \
#else
#define READ_FLIP_SIGN(dst,src)     \
#endif
#define ISQRT2 FIXR(0.70710678118654752440)
#if USE_FLOATS
#else
#endif
#if USE_FLOATS
#if HAVE_MIPSFPU
#   include "mips/compute_antialias_float.h"
#endif /* HAVE_MIPSFPU */
#else
#if HAVE_MIPSDSP
#   include "mips/compute_antialias_fixed.h"
#endif /* HAVE_MIPSDSP */
#endif /* USE_FLOATS */
#ifndef compute_antialias
#if USE_FLOATS
#define AA(j) do {                                                      \
#else
#define AA(j) do {                                              \
#endif
#endif /* compute_antialias */
#if CONFIG_MP3ADU_DECODER || CONFIG_MP3ADUFLOAT_DECODER
#endif /* CONFIG_MP3ADU_DECODER || CONFIG_MP3ADUFLOAT_DECODER */
#if CONFIG_MP3ON4_DECODER || CONFIG_MP3ON4FLOAT_DECODER
typedef struct MP3On4DecodeContext {
    int frames;                     ///< number of mp3 frames per block (number of mp3 decoder instances)
    int syncword;                   ///< syncword patch
    const uint8_t *coff;            ///< channel offsets in output buffer
    MPADecodeContext *mp3decctx[5]; ///< MPADecodeContext for every decoder instance
} MP3On4DecodeContext;
#include "mpeg4audio.h"
#endif /* CONFIG_MP3ON4_DECODER || CONFIG_MP3ON4FLOAT_DECODER */
