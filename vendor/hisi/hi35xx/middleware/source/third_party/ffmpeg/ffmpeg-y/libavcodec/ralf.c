#include "libavutil/attributes.h"
#include "libavutil/channel_layout.h"
#include "avcodec.h"
#include "get_bits.h"
#include "golomb.h"
#include "internal.h"
#include "unary.h"
#include "ralfdata.h"
#define FILTER_NONE 0
#define FILTER_RAW  642
typedef struct VLCSet {
    VLC filter_params;
    VLC bias;
    VLC coding_mode;
    VLC filter_coeffs[10][11];
    VLC short_codes[15];
    VLC long_codes[125];
} VLCSet;
#define RALF_MAX_PKT_SIZE 8192
typedef struct RALFContext {
    int version;
    int max_frame_size;
    VLCSet sets[3];
    int32_t channel_data[2][4096];

    int     filter_params;   ///< combined filter parameters for the current channel data
    int     filter_length;   ///< length of the filter for the current channel data
    int     filter_bits;     ///< filter precision for the current channel data
    int32_t filter[64];

    int     bias[2];         ///< a constant value added to channel data after filtering

    int num_blocks;          ///< number of blocks inside the frame
    int sample_offset;
    int block_size[1 << 12]; ///< size of the blocks
    int block_pts[1 << 12];  ///< block start time (in milliseconds)

    uint8_t pkt[16384];
    int     has_pkt;
} RALFContext;
#define MAX_ELEMS 644 // no RALF table uses more than that
