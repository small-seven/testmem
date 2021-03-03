#include <stddef.h>
#include <stdint.h>
#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/pixels.h"
#include "libavcodec/qpeldsp.h"
#include "fpel.h"
#define ff_put_no_rnd_pixels16_mmxext ff_put_pixels16_mmx
#define ff_put_no_rnd_pixels8_mmxext ff_put_pixels8_mmx
#if HAVE_X86ASM
#define ff_put_pixels16_mmxext ff_put_pixels16_mmx
#define ff_put_pixels8_mmxext  ff_put_pixels8_mmx
#define QPEL_OP(OPNAME, RND, MMX)                                       \
#endif /* HAVE_X86ASM */
#define SET_QPEL_FUNCS(PFX, IDX, SIZE, CPU, PREFIX)                          \
#if HAVE_MMXEXT_EXTERNAL
#endif /* HAVE_MMXEXT_EXTERNAL */
