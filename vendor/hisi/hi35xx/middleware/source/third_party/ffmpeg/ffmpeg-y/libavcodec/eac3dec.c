#include "avcodec.h"
#include "internal.h"
#include "aac_ac3_parser.h"
#include "ac3.h"
#include "ac3dec.h"
#include "ac3dec_data.h"
#include "eac3_data.h"
typedef enum {
    EAC3_GAQ_NO =0,
    EAC3_GAQ_12,
    EAC3_GAQ_14,
    EAC3_GAQ_124
} EAC3GaqMode;
#define EAC3_SR_CODE_REDUCED  3
#if USE_FIXED
#endif
#define COEFF_0 10273905LL
#define COEFF_1 11863283LL
#define COEFF_2  3070444LL
