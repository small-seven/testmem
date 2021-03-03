#include "libavutil/libm.h" // brought forward to work around cygwin header breakage
#include <float.h>
#include "libavutil/mathematics.h"
#include "mathops.h"
#include "avcodec.h"
#include "put_bits.h"
#include "aac.h"
#include "aacenc.h"
#include "aactab.h"
#include "aacenctab.h"
#include "aacenc_utils.h"
#include "aacenc_quantization.h"
#include "aacenc_is.h"
#include "aacenc_tns.h"
#include "aacenc_ltp.h"
#include "aacenc_pred.h"
#include "libavcodec/aaccoder_twoloop.h"
#define NOISE_SPREAD_THRESHOLD 0.9f
#define NOISE_LAMBDA_REPLACE 1.948f
#include "libavcodec/aaccoder_trellis.h"
typedef struct BandCodingPath {
    int prev_idx; ///< pointer to the previous path point
    float cost;   ///< path cost
    int run;
} BandCodingPath;
typedef struct TrellisPath {
    float cost;
    int prev;
} TrellisPath;
#define TRELLIS_STAGES 121
#define TRELLIS_STATES (SCALE_MAX_DIFF+1)
