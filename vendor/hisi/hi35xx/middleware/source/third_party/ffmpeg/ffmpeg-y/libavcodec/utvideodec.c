#include <inttypes.h>
#include <stdlib.h>
#define CACHED_BITSTREAM_READER !ARCH_X86_32
#define UNCHECKED_BITSTREAM_READER 1
#include "libavutil/intreadwrite.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "bswapdsp.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#include "thread.h"
#include "utvideo.h"
#define VLC_BITS 11
#undef A
#undef B
#undef C
