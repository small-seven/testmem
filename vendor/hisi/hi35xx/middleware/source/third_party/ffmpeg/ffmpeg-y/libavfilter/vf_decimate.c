#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/timestamp.h"
#include "avfilter.h"
#include "internal.h"
#define INPUT_MAIN     0
#define INPUT_CLEANSRC 1
typedef struct DecimateContext {
    const AVClass *class;
    struct qitem *queue;    ///< window of cycle frames and the associated data diff
    int fid;                ///< current frame id in the queue
    int filled;             ///< 1 if the queue is filled, 0 otherwise
    AVFrame *last;          ///< last frame from the previous queue
    AVFrame **clean_src;    ///< frame queue for the clean source
    int got_frame[2];       ///< frame request flag for each input stream
    AVRational ts_unit;     ///< timestamp units for the output frames
    int64_t start_pts;      ///< base for output timestamps
    uint32_t eof;           ///< bitmask for end of stream
    int hsub, vsub;         ///< chroma subsampling values
    int depth;
    int nxblocks, nyblocks;
    int bdiffsize;
    int64_t *bdiffs;

    /* options */
    int cycle;
    double dupthresh_flt;
    double scthresh_flt;
    int64_t dupthresh;
    int64_t scthresh;
    int blockx, blocky;
    int ppsrc;
    int chroma;
} DecimateContext;
#define OFFSET(x) offsetof(DecimateContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define CALC_DIFF(nbits) do {                               \
#define PF_NOALPHA(suf) AV_PIX_FMT_YUV420##suf,  AV_PIX_FMT_YUV422##suf,  AV_PIX_FMT_YUV444##suf
#define PF_ALPHA(suf)   AV_PIX_FMT_YUVA420##suf, AV_PIX_FMT_YUVA422##suf, AV_PIX_FMT_YUVA444##suf
#define PF(suf)         PF_NOALPHA(suf), PF_ALPHA(suf)
