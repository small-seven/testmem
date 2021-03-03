#include <string.h>
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "avcodec.h"
#include "profiles.h"
#include "version.h"
#define MT(...) (const char *const[]){ __VA_ARGS__, NULL }
