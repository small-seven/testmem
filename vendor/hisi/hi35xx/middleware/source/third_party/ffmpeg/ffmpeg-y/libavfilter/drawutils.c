#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/avutil.h"
#include "libavutil/colorspace.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "libavutil/pixdesc.h"
#include "drawutils.h"
#include "formats.h"
#define EXPAND(compn) \
