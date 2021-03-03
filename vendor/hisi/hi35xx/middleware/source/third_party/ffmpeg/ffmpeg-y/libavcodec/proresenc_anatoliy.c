#include "libavutil/opt.h"
#include "avcodec.h"
#include "dct.h"
#include "internal.h"
#include "profiles.h"
#include "proresdata.h"
#include "put_bits.h"
#include "bytestream.h"
#include "fdctdsp.h"
#define DEFAULT_SLICE_MB_WIDTH 8
typedef struct {
    AVClass *class;
    FDCTDSPContext fdsp;
    uint8_t* fill_y;
    uint8_t* fill_u;
    uint8_t* fill_v;
    uint8_t* fill_a;

    int qmat_luma[16][64];
    int qmat_chroma[16][64];
    const uint8_t *scantable;

    int is_422;
    int need_alpha;
    int is_interlaced;

    char *vendor;
} ProresContext;
#define QSCALE(qmat,ind,val) ((val) / ((qmat)[ind]))
#define TO_GOLOMB(val) (((val) << 1) ^ ((val) >> 31))
#define DIFF_SIGN(val, sign) (((val) >> 31) ^ (sign))
#define IS_NEGATIVE(val) ((((val) >> 31) ^ -1) + 1)
#define TO_GOLOMB2(val,sign) ((val)==0 ? 0 : ((val) << 1) + (sign))
#define FIRST_DC_CB 0xB8
#define OFFSET(x) offsetof(ProresContext, x)
#define VE     AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
