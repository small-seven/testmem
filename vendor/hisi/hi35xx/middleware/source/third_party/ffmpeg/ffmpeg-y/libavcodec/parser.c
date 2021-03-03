#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include "internal.h"
#include "parser.h"
#if FF_API_CONVERGENCE_DURATION
#endif
#define FILL(name) if(s->name > 0 && avctx->name <= 0) avctx->name = s->name
