#include "config.h"
#include <float.h>
#include <stdint.h>
#include "libavutil/float_dsp.h"
#include "libavutil/internal.h"
#include "checkasm.h"
#define LEN 256
#define randomize_buffer(buf)                 \
#define ARBITRARY_FMUL_ADD_CONST 0.005
#define ARBITRARY_FMUL_WINDOW_CONST 0.008
#define ARBITRARY_FMAC_SCALAR_CONST 0.005
#define ARBITRARY_DMAC_SCALAR_CONST 0.005
#define ARBITRARY_SCALARPRODUCT_CONST 0.2
