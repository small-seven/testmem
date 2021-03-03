#include "libavformat/avformat.h"
#include "libavutil/opt.h"
#include "decklink_common_c.h"
#include "decklink_dec.h"
#define OFFSET(x) offsetof(struct decklink_cctx, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
