#define FFT_FLOAT 0
#undef CONFIG_AC3ENC_FLOAT
#include "internal.h"
#include "audiodsp.h"
#include "ac3enc.h"
#include "eac3enc.h"
#define AC3ENC_TYPE AC3ENC_TYPE_AC3_FIXED
#include "ac3enc_opts_template.c"
#include "ac3enc_template.c"
