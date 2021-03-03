#include "xface.h"
#include "avcodec.h"
#include "internal.h"
#include "libavutil/avassert.h"
typedef struct XFaceContext {
    AVClass *class;
    uint8_t bitmap[XFACE_PIXELS]; ///< image used internally for decoding
    int max_line_len;             ///< max line length for compressed data
    int set_header;               ///< set X-Face header in the output
} XFaceContext;
typedef struct {
    ProbRange prob_ranges[XFACE_PIXELS*2];
    int prob_ranges_idx;
} ProbRangesQueue;
