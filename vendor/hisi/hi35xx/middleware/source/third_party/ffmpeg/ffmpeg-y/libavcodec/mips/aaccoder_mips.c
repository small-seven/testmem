#include "libavutil/libm.h"
#include <float.h>
#include "libavutil/mathematics.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/put_bits.h"
#include "libavcodec/aac.h"
#include "libavcodec/aacenc.h"
#include "libavcodec/aactab.h"
#include "libavcodec/aacenctab.h"
#include "libavcodec/aacenc_utils.h"
#if HAVE_INLINE_ASM
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
typedef struct BandCodingPath {
    int prev_idx;
    float cost;
    int run;
} BandCodingPath;
#define quantize_and_encode_band_cost(                                       \
#define get_band_numbits(                                  \
#if HAVE_MIPSFPU
#define get_band_cost(                                  \
#include "libavcodec/aacenc_quantization_misc.h"
#include "libavcodec/aaccoder_twoloop.h"
#endif /*HAVE_MIPSFPU */
#include "libavcodec/aaccoder_trellis.h"
#endif /* !HAVE_MIPS32R6 && !HAVE_MIPS64R6 */
#endif /* HAVE_INLINE_ASM */
#if HAVE_INLINE_ASM
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
#if HAVE_MIPSFPU
#endif /* HAVE_MIPSFPU */
#if HAVE_MIPSFPU
#endif /* HAVE_MIPSFPU */
#endif /* !HAVE_MIPS32R6 && !HAVE_MIPS64R6 */
#endif /* HAVE_INLINE_ASM */
