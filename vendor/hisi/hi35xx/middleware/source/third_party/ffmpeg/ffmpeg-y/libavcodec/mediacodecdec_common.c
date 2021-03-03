#include <string.h>
#include <sys/types.h>
#include "libavutil/common.h"
#include "libavutil/hwcontext_mediacodec.h"
#include "libavutil/mem.h"
#include "libavutil/log.h"
#include "libavutil/pixfmt.h"
#include "libavutil/time.h"
#include "libavutil/timestamp.h"
#include "avcodec.h"
#include "internal.h"
#include "mediacodec.h"
#include "mediacodec_surface.h"
#include "mediacodec_sw_buffer.h"
#include "mediacodec_wrapper.h"
#include "mediacodecdec_common.h"
#define INPUT_DEQUEUE_TIMEOUT_US 8000
#define OUTPUT_DEQUEUE_TIMEOUT_US 8000
#define OUTPUT_DEQUEUE_BLOCK_TIMEOUT_US 1000000
#if FF_API_PKT_PTS
#endif
#if FF_API_PKT_PTS
#endif
#define AMEDIAFORMAT_GET_INT32(name, key, mandatory) do {                              \
