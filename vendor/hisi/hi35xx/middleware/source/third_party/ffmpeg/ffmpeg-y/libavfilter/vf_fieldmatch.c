#include <inttypes.h>
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/timestamp.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
#define INPUT_MAIN     0
#define INPUT_CLEANSRC 1
typedef struct FieldMatchContext {
    const AVClass *class;

    AVFrame *prv,  *src,  *nxt;     ///< main sliding window of 3 frames
    AVFrame *prv2, *src2, *nxt2;    ///< sliding window of the optional second stream
    int got_frame[2];               ///< frame request flag for each input stream
    int hsub, vsub;                 ///< chroma subsampling values
    int bpc;                        ///< bytes per component
    uint32_t eof;                   ///< bitmask for end of stream
    int64_t lastscdiff;
    int64_t lastn;

    /* options */
    int order;
    int ppsrc;
    int mode;                       ///< matching_mode
    int field;
    int mchroma;
    int y0, y1;
    int64_t scthresh;
    double scthresh_flt;
    int combmatch;                  ///< comb_matching_mode
    int combdbg;
    int cthresh;
    int chroma;
    int blockx, blocky;
    int combpel;

    /* misc buffers */
    uint8_t *map_data[4];
    int map_linesize[4];
    uint8_t *cmask_data[4];
    int cmask_linesize[4];
    int *c_array;
    int tpitchy, tpitchuv;
    uint8_t *tbuffer;
} FieldMatchContext;
#define OFFSET(x) offsetof(FieldMatchContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define FILTER(xm2, xm1, xp1, xp2) \
#define HAS_FF_AROUND(p, lz) (p[(x)-1 - (lz)] == 0xff || p[(x) - (lz)] == 0xff || p[(x)+1 - (lz)] == 0xff || \
#define C_ARRAY_ADD(v) do {                         \
#define VERTICAL_HALF(y_start, y_end) do {                                  \
#define LOAD_COMB(mid) do {                                                     \
#define SLIDING_FRAME_WINDOW(prv, src, nxt) do {                \
