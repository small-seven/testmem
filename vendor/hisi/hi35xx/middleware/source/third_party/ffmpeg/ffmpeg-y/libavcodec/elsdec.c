#include <math.h>
#include <stdint.h>
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "elsdec.h"
#define ELS_JOTS_PER_BYTE   36
#define ELS_MAX             (1 << 24)
#define RUNG_SPACE          (64 * sizeof(ElsRungNode))
