#include "libavutil/common.h"
#include "avcodec.h"
#include "get_bits.h"
#include "dcahuff.h"
#define TMODE_COUNT 4
#define BITALLOC_12_VLC_BITS 9
#define SCALES_COUNT    5
#define SCALES_VLC_BITS 9
#define DCA_INIT_VLC(vlc, a, b, c, d)                                       \
#define LBR_INIT_VLC(vlc, tab, nb_bits)                                 \
