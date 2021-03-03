#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "fdctdsp.h"
#include "put_bits.h"
#include "profiles.h"
#include "bytestream.h"
#include "internal.h"
#include "proresdata.h"
#define CFACTOR_Y422 2
#define CFACTOR_Y444 3
#define MAX_MBS_PER_SLICE 8
#define MAX_PLANES 4
#define NUM_MB_LIMITS 4
#define TRELLIS_WIDTH 16
#define SCORE_LIMIT   INT_MAX / 2
#define MAX_STORED_Q 16
typedef struct ProresThreadData {
    DECLARE_ALIGNED(16, int16_t, blocks)[MAX_PLANES][64 * 4 * MAX_MBS_PER_SLICE];
    DECLARE_ALIGNED(16, uint16_t, emu_buf)[16 * 16];
    int16_t custom_q[64];
    int16_t custom_chroma_q[64];
    struct TrellisNode *nodes;
} ProresThreadData;
typedef struct ProresContext {
    AVClass *class;
    DECLARE_ALIGNED(16, int16_t, blocks)[MAX_PLANES][64 * 4 * MAX_MBS_PER_SLICE];
    DECLARE_ALIGNED(16, uint16_t, emu_buf)[16*16];
    int16_t quants[MAX_STORED_Q][64];
    int16_t quants_chroma[MAX_STORED_Q][64];
    int16_t custom_q[64];
    int16_t custom_chroma_q[64];
    const uint8_t *quant_mat;
    const uint8_t *quant_chroma_mat;
    const uint8_t *scantable;

    void (*fdct)(FDCTDSPContext *fdsp, const uint16_t *src,
                 ptrdiff_t linesize, int16_t *block);
    FDCTDSPContext fdsp;

    const AVFrame *pic;
    int mb_width, mb_height;
    int mbs_per_slice;
    int num_chroma_blocks, chroma_factor;
    int slices_width;
    int slices_per_picture;
    int pictures_per_frame; // 1 for progressive, 2 for interlaced
    int cur_picture_idx;
    int num_planes;
    int bits_per_mb;
    int force_quant;
    int alpha_bits;
    int warn;

    char *vendor;
    int quant_sel;

    int frame_size_upper_bound;

    int profile;
    const struct prores_profile *profile_info;

    int *slice_q;

    ProresThreadData *tdata;
} ProresContext;
#define GET_SIGN(x)  ((x) >> 31)
#define MAKE_CODE(x) ((((x)) * 2) ^ GET_SIGN(x))
#if FF_API_CODED_FRAME
#endif
#define OFFSET(x) offsetof(ProresContext, x)
#define VE     AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
