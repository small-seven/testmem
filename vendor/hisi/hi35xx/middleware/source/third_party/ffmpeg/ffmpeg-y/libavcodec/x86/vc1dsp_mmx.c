#include "libavutil/cpu.h"
#include "libavutil/mem.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/vc1dsp.h"
#include "constants.h"
#include "fpel.h"
#include "vc1dsp.h"
#if HAVE_6REGS && HAVE_INLINE_ASM && HAVE_MMX_EXTERNAL
#define OP_PUT(S,D)
#define OP_AVG(S,D) "pavgb " #S ", " #D " \n\t"
#define NORMALIZE_MMX(SHIFT)                                    \
#define TRANSFER_DO_PACK(OP)                    \
#define TRANSFER_DONT_PACK(OP)                  \
#define DO_UNPACK(reg)  "punpcklbw %%mm0, " reg "\n\t"
#define DONT_UNPACK(reg)
#define LOAD_ROUNDER_MMX(ROUND)                 \
#define VC1_SHIFT2(OP, OPNAME)\
#define MSPEL_FILTER13_CORE(UNPACK, MOVQ, A1, A2, A3, A4)       \
#define MSPEL_FILTER13_VER_16B(NAME, A1, A2, A3, A4)                    \
#define MSPEL_FILTER13_HOR_16B(NAME, A1, A2, A3, A4, OP, OPNAME)        \
#define MSPEL_FILTER13_8B(NAME, A1, A2, A3, A4, OP, OPNAME)             \
typedef void (*vc1_mspel_mc_filter_ver_16bits)(int16_t *dst, const uint8_t *src, x86_reg src_stride, int rnd, int64_t shift);
typedef void (*vc1_mspel_mc_filter_hor_16bits)(uint8_t *dst, x86_reg dst_stride, const int16_t *src, int rnd);
typedef void (*vc1_mspel_mc_filter_8bits)(uint8_t *dst, const uint8_t *src, x86_reg stride, int rnd, x86_reg offset);

/**
 * Interpolate fractional pel values by applying proper vertical then
 * horizontal filter.
 *
 * @param  dst     Destination buffer for interpolated pels.
 * @param  src     Source buffer.
 * @param  stride  Stride for both src and dst buffers.
 * @param  hmode   Horizontal filter (expressed in quarter pixels shift).
 * @param  hmode   Vertical filter.
 * @param  rnd     Rounding bias.
 */
#define VC1_MSPEL_MC(OP, INSTR)\
static void OP ## vc1_mspel_mc(uint8_t *dst, const uint8_t *src, int stride,\
                               int hmode, int vmode, int rnd)\
{\
    static const vc1_mspel_mc_filter_ver_16bits vc1_put_shift_ver_16bits[] =\
         { NULL, vc1_put_ver_16b_shift1_mmx, ff_vc1_put_ver_16b_shift2_mmx, vc1_put_ver_16b_shift3_mmx };\
#define DECLARE_FUNCTION(a, b)                                          \
#define FN_ASSIGN(OP, X, Y, INSN) \
#endif /* HAVE_6REGS && HAVE_INLINE_ASM && HAVE_MMX_EXTERNAL */
