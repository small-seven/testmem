#include "libavutil/channel_layout.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/intfloat.h"
#include "avformat.h"
#include "internal.h"
#include "riff.h"
typedef struct NUVContext {
    int v_id;
    int a_id;
    int rtjpg_video;
} NUVContext;
typedef enum {
    NUV_VIDEO     = 'V',
    NUV_EXTRADATA = 'D',
    NUV_AUDIO     = 'A',
    NUV_SEEKP     = 'R',
    NUV_MYTHEXT   = 'X'
} nuv_frametype;
#define PKTSIZE(s) (s &  0xffffff)
#if FF_API_R_FRAME_RATE
#endif
#define HDRSIZE 12
