#include "libavutil/adler32.h"
#include "libavutil/avassert.h"
#include "libavutil/bprint.h"
#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "avformat.h"
#include "internal.h"
#define DEFINE_CKSUM_LINE(name, type, conv) \
