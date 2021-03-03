#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/parseutils.h"
#include "htmlsubtitles.h"
#include <ctype.h>
#define LIKELY_A_TAG_CHAR(x) (((x) >= '0' && (x) <= '9') || \
