#include <math.h>
#include "sipr.h"
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/float_dsp.h"
#include "libavutil/mathematics.h"
#include "lsp.h"
#include "acelp_vectors.h"
#include "acelp_pitch_delay.h"
#include "acelp_filters.h"
#include "celp_filters.h"
#include "sipr16kdata.h"
#define DIVIDE_BY_3(x) ((x) * 10923 >> 15)
