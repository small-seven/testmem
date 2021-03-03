#include <math.h>
#include <stdint.h>
#include <string.h>
#include "libavutil/channel_layout.h"
#include "libavutil/float_dsp.h"
#include "libavutil/mathematics.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#include "lsp.h"
#include "acelp_vectors.h"
#include "acelp_pitch_delay.h"
#include "acelp_filters.h"
#include "celp_filters.h"
#define MAX_SUBFRAME_COUNT   5
#include "sipr.h"
#include "siprdata.h"
typedef struct SiprModeParam {
    const char *mode_name;
    uint16_t bits_per_frame;
    uint8_t subframe_count;
    uint8_t frames_per_packet;
    float pitch_sharp_factor;

    /* bitstream parameters */
    uint8_t number_of_fc_indexes;
    uint8_t ma_predictor_bits;  ///< size in bits of the switched MA predictor

    /** size in bits of the i-th stage vector of quantizer */
    uint8_t vq_indexes_bits[5];

    /** size in bits of the adaptive-codebook index for every subframe */
    uint8_t pitch_delay_bits[5];

    uint8_t gp_index_bits;
    uint8_t fc_index_bits[10]; ///< size in bits of the fixed codebook indexes
    uint8_t gc_index_bits;     ///< size in bits of the gain  codebook indexes
} SiprModeParam;
