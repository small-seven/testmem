#include "libavutil/attributes.h"
#include "libavutil/samplefmt.h"
#include "flacdsp.h"
#include "config.h"
#define SAMPLE_SIZE 16
#define PLANAR 0
#include "flacdsp_template.c"
#include "flacdsp_lpc_template.c"
#undef  PLANAR
#define PLANAR 1
#include "flacdsp_template.c"
#undef  SAMPLE_SIZE
#undef  PLANAR
#define SAMPLE_SIZE 32
#define PLANAR 0
#include "flacdsp_template.c"
#include "flacdsp_lpc_template.c"
#undef  PLANAR
#define PLANAR 1
#include "flacdsp_template.c"
