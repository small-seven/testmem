#include "avcodec.h"
#include "internal.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "msmpeg4.h"
#include "libavutil/imgutils.h"
#include "h263.h"
#include "mpeg4video.h"
#include "msmpeg4data.h"
#include "vc1data.h"
#include "wmv2.h"
#define DC_VLC_BITS 9
#define V2_INTRA_CBPC_VLC_BITS 3
#define V2_MB_TYPE_VLC_BITS 7
#define MV_VLC_BITS 9
#define V2_MV_VLC_BITS 9
#define TEX_VLC_BITS 9
#define DEFAULT_INTER_INDEX 3
