#include <inttypes.h>
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "canopus.h"
#include "get_bits.h"
#include "internal.h"
#include "thread.h"
#include "hqx.h"
#include "hqxdsp.h"
#define HQX_HEADER_SIZE 59
