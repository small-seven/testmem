#include "libavformat/avformat.h"
#include "libavutil/opt.h"
#include "decklink_common_c.h"
#include "decklink_enc.h"
#define OFFSET(x) offsetof(struct decklink_cctx, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
