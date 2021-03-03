#include "libavutil/avassert.h"
#include "avcodec.h"
#include "mpeg_er.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "h263.h"
#include "h261.h"
#include "internal.h"
#define H261_MBA_VLC_BITS 9
#define H261_MTYPE_VLC_BITS 6
#define H261_MV_VLC_BITS 7
#define H261_CBP_VLC_BITS 9
#define TCOEFF_VLC_BITS 9
#define MBA_STUFFING 33
#define MBA_STARTCODE 34
