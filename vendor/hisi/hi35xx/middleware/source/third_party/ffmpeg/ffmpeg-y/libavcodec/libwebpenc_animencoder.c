#include "config.h"
#include "libwebpenc_common.h"
#include <webp/mux.h>
typedef struct LibWebPAnimContext {
    LibWebPContextCommon cc;
    WebPAnimEncoder *enc;     // the main AnimEncoder object
    int64_t prev_frame_pts;   // pts of the previously encoded frame.
    int done;                 // If true, we have assembled the bitstream already
} LibWebPAnimContext;
