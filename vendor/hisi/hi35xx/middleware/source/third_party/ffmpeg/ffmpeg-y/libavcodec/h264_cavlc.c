#define CABAC(h) 0
#define UNCHECKED_BITSTREAM_READER 1
#include "internal.h"
#include "avcodec.h"
#include "h264dec.h"
#include "h264_mvpred.h"
#include "h264data.h"
#include "golomb.h"
#include "mpegutils.h"
#include "libavutil/avassert.h"
#define LEVEL_TAB_BITS 8
#define CHROMA_DC_COEFF_TOKEN_VLC_BITS 8
#define CHROMA422_DC_COEFF_TOKEN_VLC_BITS 13
#define COEFF_TOKEN_VLC_BITS           8
#define TOTAL_ZEROS_VLC_BITS           9
#define CHROMA_DC_TOTAL_ZEROS_VLC_BITS 3
#define CHROMA422_DC_TOTAL_ZEROS_VLC_BITS 5
#define RUN_VLC_BITS                   3
#define RUN7_VLC_BITS                  6
#define STORE_BLOCK(type) \
