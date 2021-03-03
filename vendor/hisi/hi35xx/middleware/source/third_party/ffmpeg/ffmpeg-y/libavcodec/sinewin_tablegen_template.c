#include <stdlib.h>
#include "libavcodec/aac_defines.h"
#define CONFIG_HARDCODED_TABLES 0
#if USE_FIXED
#define WRITE_FUNC write_int32_t_array
#else
#define WRITE_FUNC write_float_array
#endif
#define SINETABLE_CONST
#define SINETABLE(size) \
#define SINETABLE120960(size) \
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
#include "sinewin_tablegen.h"
#include "tableprint.h"
