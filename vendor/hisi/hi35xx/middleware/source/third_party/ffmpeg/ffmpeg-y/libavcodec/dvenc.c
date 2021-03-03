#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "dv.h"
#include "dv_profile_internal.h"
#include "dv_tablegen.h"
#include "fdctdsp.h"
#include "internal.h"
#include "mathops.h"
#include "me_cmp.h"
#include "pixblockdsp.h"
#include "put_bits.h"
#if CONFIG_SMALL
#else
#endif
typedef struct EncBlockInfo {
    int      area_q[4];
    int      bit_size[4];
    int      prev[5];
    int      cur_ac;
    int      cno;
    int      dct_mode;
    int16_t  mb[64];
    uint8_t  next[64];
    uint8_t  sign[64];
    uint8_t  partial_bit_count;
    uint32_t partial_bit_buffer; /* we can't use uint16_t here */
} EncBlockInfo;
#if 0 /* SMPTE spec method */
#else /* improved FFmpeg method */
#endif
#if FF_API_CODED_FRAME
#endif
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#define OFFSET(x) offsetof(DVVideoContext, x)
