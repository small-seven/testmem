#include "libavutil/opt.h"
#include "libavutil/channel_layout.h"
#include "dcadec.h"
#include "dcahuff.h"
#include "dca_syncwords.h"
#include "profiles.h"
#define MIN_PACKET_SIZE     16
#define MAX_PACKET_SIZE     0x104000
#define OFFSET(x) offsetof(DCAContext, x)
#define PARAM AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_DECODING_PARAM
