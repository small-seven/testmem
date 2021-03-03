#include "libavutil/attributes.h"
#include "libavutil/buffer.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#include "thread.h"
#include "cfhd.h"
#define ALPHA_COMPAND_DC_OFFSET 256
#define ALPHA_COMPAND_GAIN 9400
