#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/cpu.h"
#include "libavutil/mem.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/videodsp.h"
#if HAVE_X86ASM
typedef void emu_edge_vfix_func(uint8_t *dst, x86_reg dst_stride,
                                const uint8_t *src, x86_reg src_stride,
                                x86_reg start_y, x86_reg end_y, x86_reg bh);
typedef void emu_edge_vvar_func(uint8_t *dst, x86_reg dst_stride,
                                const uint8_t *src, x86_reg src_stride,
                                x86_reg start_y, x86_reg end_y, x86_reg bh,
                                x86_reg w);

extern emu_edge_vfix_func ff_emu_edge_vfix1_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix2_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix3_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix4_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix5_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix6_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix7_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix8_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix9_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix10_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix11_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix12_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix13_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix14_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix15_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix16_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix17_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix18_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix19_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix20_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix21_mmx;
extern emu_edge_vfix_func ff_emu_edge_vfix22_mmx;
#if ARCH_X86_32
static emu_edge_vfix_func * const vfixtbl_mmx[22] = {
    &ff_emu_edge_vfix1_mmx,  &ff_emu_edge_vfix2_mmx,  &ff_emu_edge_vfix3_mmx,
    &ff_emu_edge_vfix4_mmx,  &ff_emu_edge_vfix5_mmx,  &ff_emu_edge_vfix6_mmx,
    &ff_emu_edge_vfix7_mmx,  &ff_emu_edge_vfix8_mmx,  &ff_emu_edge_vfix9_mmx,
    &ff_emu_edge_vfix10_mmx, &ff_emu_edge_vfix11_mmx, &ff_emu_edge_vfix12_mmx,
    &ff_emu_edge_vfix13_mmx, &ff_emu_edge_vfix14_mmx, &ff_emu_edge_vfix15_mmx,
    &ff_emu_edge_vfix16_mmx, &ff_emu_edge_vfix17_mmx, &ff_emu_edge_vfix18_mmx,
    &ff_emu_edge_vfix19_mmx, &ff_emu_edge_vfix20_mmx, &ff_emu_edge_vfix21_mmx,
    &ff_emu_edge_vfix22_mmx
};
#endif
typedef void emu_edge_hfix_func(uint8_t *dst, x86_reg dst_stride,
                                x86_reg start_x, x86_reg bh);
typedef void emu_edge_hvar_func(uint8_t *dst, x86_reg dst_stride,
                                x86_reg start_x, x86_reg n_words, x86_reg bh);

extern emu_edge_hfix_func ff_emu_edge_hfix2_mmx;
extern emu_edge_hfix_func ff_emu_edge_hfix4_mmx;
extern emu_edge_hfix_func ff_emu_edge_hfix6_mmx;
extern emu_edge_hfix_func ff_emu_edge_hfix8_mmx;
extern emu_edge_hfix_func ff_emu_edge_hfix10_mmx;
extern emu_edge_hfix_func ff_emu_edge_hfix12_mmx;
extern emu_edge_hfix_func ff_emu_edge_hfix14_mmx;
extern emu_edge_hfix_func ff_emu_edge_hfix16_mmx;
extern emu_edge_hfix_func ff_emu_edge_hfix18_mmx;
extern emu_edge_hfix_func ff_emu_edge_hfix20_mmx;
extern emu_edge_hfix_func ff_emu_edge_hfix22_mmx;
#if ARCH_X86_32
static emu_edge_hfix_func * const hfixtbl_mmx[11] = {
    ff_emu_edge_hfix2_mmx,  ff_emu_edge_hfix4_mmx,  ff_emu_edge_hfix6_mmx,
    ff_emu_edge_hfix8_mmx,  ff_emu_edge_hfix10_mmx, ff_emu_edge_hfix12_mmx,
    ff_emu_edge_hfix14_mmx, ff_emu_edge_hfix16_mmx, ff_emu_edge_hfix18_mmx,
    ff_emu_edge_hfix20_mmx, ff_emu_edge_hfix22_mmx
};
#endif
#if HAVE_AVX2_EXTERNAL
#endif
#if ARCH_X86_32
#endif
#if HAVE_AVX2_EXTERNAL
#endif /* HAVE_AVX2_EXTERNAL */
#endif /* HAVE_X86ASM */
#if HAVE_X86ASM
#if ARCH_X86_32
#endif /* ARCH_X86_32 */
#if ARCH_X86_32
#endif /* ARCH_X86_32 */
#if HAVE_AVX2_EXTERNAL
#endif
#endif /* HAVE_X86ASM */
