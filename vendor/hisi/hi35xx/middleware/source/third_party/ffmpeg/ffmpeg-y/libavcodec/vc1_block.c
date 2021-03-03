#include "avcodec.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "msmpeg4data.h"
#include "unary.h"
#include "vc1.h"
#include "vc1_pred.h"
#include "vc1acdata.h"
#include "vc1data.h"
#define MB_INTRA_VLC_BITS 9
#define DC_VLC_BITS 9
#define inc_blk_idx(idx) do { \
#define GET_MQUANT()                                           \
#define GET_MVDATA(_dmv_x, _dmv_y)                                      \
