#include <limits.h>
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "put_bits.h"
typedef struct Float11 {
    uint8_t sign;   /**< 1 bit sign */
    uint8_t exp;    /**< 4 bits exponent */
    uint8_t mant;   /**< 6 bits mantissa */
} Float11;
typedef struct G726Tables {
    const int* quant;         /**< quantization table */
    const int16_t* iquant;    /**< inverse quantization table */
    const int16_t* W;         /**< special table #1 ;-) */
    const uint8_t* F;         /**< special table #2 */
} G726Tables;
typedef struct G726Context {
    AVClass *class;
    G726Tables tbls;    /**< static tables needed for computation */

    Float11 sr[2];      /**< prev. reconstructed samples */
    Float11 dq[6];      /**< prev. difference */
    int a[2];           /**< second order predictor coeffs */
    int b[6];           /**< sixth order predictor coeffs */
    int pk[2];          /**< signs of prev. 2 sez + dq */

    int ap;             /**< scale factor control */
    int yu;             /**< fast scale factor */
    int yl;             /**< slow scale factor */
    int dms;            /**< short average magnitude of F[i] */
    int dml;            /**< long average magnitude of F[i] */
    int td;             /**< tone detect */

    int se;             /**< estimated signal for the next iteration */
    int sez;            /**< estimated second order prediction */
    int y;              /**< quantizer scaling factor for the next iteration */
    int code_size;
    int little_endian;  /**< little-endian bitstream as used in aiff and Sun AU */
} G726Context;
#if CONFIG_ADPCM_G726_ENCODER || CONFIG_ADPCM_G726LE_ENCODER
#define OFFSET(x) offsetof(G726Context, x)
#define AE AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#endif
#if CONFIG_ADPCM_G726_ENCODER
#endif
#if CONFIG_ADPCM_G726LE_ENCODER
#endif
#if CONFIG_ADPCM_G726_DECODER || CONFIG_ADPCM_G726LE_DECODER
#endif
#if CONFIG_ADPCM_G726_DECODER
#endif
#if CONFIG_ADPCM_G726LE_DECODER
#endif
