#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/mathematics.h"
#include "libavutil/samplefmt.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct Buf {
    AVFrame *frame;
    struct Buf        *next;
} Buf;
typedef struct FifoContext {
    Buf  root;
    Buf *last;   ///< last buffered frame

    /**
     * When a specific number of output samples is requested, the partial
     * buffer is stored here
     */
    AVFrame *out;
    int allocated_samples;      ///< number of samples out was allocated for
} FifoContext;
