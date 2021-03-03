#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "cabac_functions.h"
#include "hevc_data.h"
#include "hevc.h"
#include "hevcdec.h"
#define CABAC_MAX_BIN 31
#define CNU 154
#define GET_CABAC(ctx) get_cabac(&s->HEVClc->cc, &s->HEVClc->cabac_state[ctx])
#define GET_COORD(offset, n)                                    \
