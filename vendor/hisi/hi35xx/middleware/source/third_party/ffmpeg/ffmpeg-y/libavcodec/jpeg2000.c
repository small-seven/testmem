#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "internal.h"
#include "jpeg2000.h"
#define SHL(a, n) ((n) >= 0 ? (a) << (n) : (a) >> -(n))
