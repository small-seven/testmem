#include "libavutil/time_internal.h"
#include "avformat.h"
#include "internal.h"
#define ISLEAP(y) (((y) % 4 == 0) && (((y) % 100) != 0 || ((y) % 400) == 0))
#define LEAPS_COUNT(y) ((y)/4 - (y)/100 + (y)/400)
