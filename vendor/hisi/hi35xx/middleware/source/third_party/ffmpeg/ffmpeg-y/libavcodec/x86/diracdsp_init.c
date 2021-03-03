#include "libavutil/x86/cpu.h"
#include "libavcodec/diracdsp.h"
#include "fpel.h"
#if HAVE_X86ASM
#define HPEL_FILTER(MMSIZE, EXT)                                                             \
#define PIXFUNC(PFX, IDX, EXT)                                                   \
#define DIRAC_PIXOP(OPNAME2, OPNAME, EXT)\
#else // HAVE_X86ASM
#define HPEL_FILTER(MMSIZE, EXT)                                                     \
#define PIXFUNC(PFX, IDX, EXT) do {} while (0)
#endif // HAVE_X86ASM
#if !ARCH_X86_64
#endif
#if !ARCH_X86_64
#endif
