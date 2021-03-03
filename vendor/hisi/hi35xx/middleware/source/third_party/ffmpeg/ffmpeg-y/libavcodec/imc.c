#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "libavutil/channel_layout.h"
#include "libavutil/ffmath.h"
#include "libavutil/float_dsp.h"
#include "libavutil/internal.h"
#include "avcodec.h"
#include "bswapdsp.h"
#include "get_bits.h"
#include "fft.h"
#include "internal.h"
#include "sinewin.h"
#include "imcdata.h"
#define IMC_BLOCK_SIZE 64
#define IMC_FRAME_ID 0x21
#define BANDS 32
#define COEFFS 256
typedef struct IMCChannel {
    float old_floor[BANDS];
    float flcoeffs1[BANDS];
    float flcoeffs2[BANDS];
    float flcoeffs3[BANDS];
    float flcoeffs4[BANDS];
    float flcoeffs5[BANDS];
    float flcoeffs6[BANDS];
    float CWdecoded[COEFFS];

    int bandWidthT[BANDS];     ///< codewords per band
    int bitsBandT[BANDS];      ///< how many bits per codeword in band
    int CWlengthT[COEFFS];     ///< how many bits in each codeword
    int levlCoeffBuf[BANDS];
    int bandFlagsBuf[BANDS];   ///< flags for each band
    int sumLenArr[BANDS];      ///< bits for all coeffs in band
    int skipFlagRaw[BANDS];    ///< skip flags are stored in raw form or not
    int skipFlagBits[BANDS];   ///< bits used to code skip flags
    int skipFlagCount[BANDS];  ///< skipped coefficients per band
    int skipFlags[COEFFS];     ///< skip coefficient decoding or not
    int codewords[COEFFS];     ///< raw codewords read from bitstream

    float last_fft_im[COEFFS];

    int decoder_reset;
} IMCChannel;
typedef struct IMCContext {
    IMCChannel chctx[2];

    /** MDCT tables */
    //@{
    float mdct_sine_window[COEFFS];
    float post_cos[COEFFS];
    float post_sin[COEFFS];
    float pre_coef1[COEFFS];
    float pre_coef2[COEFFS];
    //@}
#define VLC_TABLES_SIZE 9512
#if CONFIG_IMC_DECODER
#endif
#if CONFIG_IAC_DECODER
#endif
