#include <time.h>
#include "avstring.h"
#include "avutil.h"
#include "common.h"
#include "eval.h"
#include "log.h"
#include "random_seed.h"
#include "time_internal.h"
#include "parseutils.h"
#include "time.h"
#ifdef TEST
#define av_get_random_seed av_get_random_seed_deterministic
#define av_gettime() 1331972053200000
#endif
typedef struct VideoSizeAbbr {
    const char *abbr;
    int width, height;
} VideoSizeAbbr;
typedef struct VideoRateAbbr {
    const char *abbr;
    AVRational rate;
} VideoRateAbbr;
typedef struct ColorEntry {
    const char *name;            ///< a string representing the name of the color
    uint8_t     rgb_color[3];    ///< RGB values for the color
} ColorEntry;
#define ALPHA_SEP '@'
