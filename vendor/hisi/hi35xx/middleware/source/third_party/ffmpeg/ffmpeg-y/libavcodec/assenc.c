#include <string.h>
#include "avcodec.h"
#include "ass.h"
#include "libavutil/avstring.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
typedef struct {
    int id; ///< current event id, ReadOrder field
} ASSEncodeContext;
#if FF_API_ASS_TIMING
#define SKIP_ENTRY(ptr) do {        \
#endif
#if CONFIG_SSA_ENCODER
#endif
#if CONFIG_ASS_ENCODER
#endif
