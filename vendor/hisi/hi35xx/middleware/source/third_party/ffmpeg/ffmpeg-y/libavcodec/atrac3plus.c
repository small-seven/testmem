#include "libavutil/avassert.h"
#include "avcodec.h"
#include "get_bits.h"
#include "atrac3plus.h"
#include "atrac3plus_data.h"
#define UNPACK_SF_VQ_SHAPE(gb, dst, num_vals)                            \
#define DEC_CT_IDX_COMMON(OP)                                           \
#define CODING_DIRECT get_bits(gb, num_bits)
#define CODING_VLC get_vlc2(gb, vlc_tab->table, vlc_tab->bits, 1)
#define CODING_VLC_DELTA                                                \
#define CODING_VLC_DIFF                                                 \
