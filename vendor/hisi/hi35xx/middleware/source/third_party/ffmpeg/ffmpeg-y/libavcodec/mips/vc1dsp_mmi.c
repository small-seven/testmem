#include "libavutil/avassert.h"
#include "libavcodec/vc1dsp.h"
#include "constants.h"
#include "vc1dsp_mips.h"
#include "hpeldsp_mips.h"
#include "libavutil/mips/mmiutils.h"
#define VC1_INV_TRANCS_8_TYPE1(o1, o2, r1, r2, r3, r4, c0)                  \
#define VC1_INV_TRANCS_8_TYPE2(o1, o2, r1, r2, r3, r4, c0, c1)              \
#if _MIPS_SIM != _ABIO32
#endif
#if _MIPS_SIM != _ABIO32
#endif
#if _MIPS_SIM != _ABIO32
#endif
#define OP_PUT(S, D)
#define OP_AVG(S, D)                                                        \
#define NORMALIZE_MMI(SHIFT)                                                \
#define TRANSFER_DO_PACK(OP)                                                \
#define TRANSFER_DONT_PACK(OP)                                              \
#define DO_UNPACK(reg)                                                      \
#define DONT_UNPACK(reg)
#define LOAD_ROUNDER_MMI(ROUND)                                             \
#define SHIFT2_LINE(OFF, R0, R1, R2, R3)                                    \
#define VC1_HOR_16B_SHIFT2(OP, OPNAME)                                      \
#define VC1_SHIFT2(OP, OPNAME)\
#define MSPEL_FILTER13_CORE(UNPACK, LOAD, M, A1, A2, A3, A4)                \
#define MSPEL_FILTER13_VER_16B(NAME, A1, A2, A3, A4)                        \
#define MSPEL_FILTER13_HOR_16B(NAME, A1, A2, A3, A4, OP, OPNAME)            \
#define MSPEL_FILTER13_8B(NAME, A1, A2, A3, A4, OP, OPNAME)                 \
typedef void (*vc1_mspel_mc_filter_ver_16bits)
             (int16_t *dst, const uint8_t *src, mips_reg src_stride, int rnd,
              int64_t shift);
typedef void (*vc1_mspel_mc_filter_hor_16bits)
             (uint8_t *dst, mips_reg dst_stride, const int16_t *src, int rnd);
typedef void (*vc1_mspel_mc_filter_8bits)
             (uint8_t *dst, const uint8_t *src, mips_reg stride, int rnd,
              mips_reg offset);

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
#define VC1_MSPEL_MC(OP)                                                    \
static void OP ## vc1_mspel_mc(uint8_t *dst, const uint8_t *src, int stride,\
                               int hmode, int vmode, int rnd)               \
{                                                                           \
    static const vc1_mspel_mc_filter_ver_16bits vc1_put_shift_ver_16bits[] =\
         { NULL, vc1_put_ver_16b_shift1_mmi,                                \
                 vc1_put_ver_16b_shift2_mmi,                                \
                 vc1_put_ver_16b_shift3_mmi };                              \
#define DECLARE_FUNCTION(a, b)                                              \
#define CHROMA_MC_8_MMI                                                     \
#define CHROMA_MC_4_MMI                                                     \
