#include "libavutil/cpu.h"
#include "libavutil/x86/asm.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/snow.h"
#include "libavcodec/snow_dwt.h"
#if HAVE_INLINE_ASM
#if HAVE_7REGS
#define snow_vertical_compose_sse2_load_add(op,r,t0,t1,t2,t3)\
#define snow_vertical_compose_sse2_load(r,t0,t1,t2,t3)\
#define snow_vertical_compose_sse2_add(r,t0,t1,t2,t3)\
#define snow_vertical_compose_r2r_sub(s0,s1,s2,s3,t0,t1,t2,t3)\
#define snow_vertical_compose_sse2_store(w,s0,s1,s2,s3)\
#define snow_vertical_compose_sra(n,t0,t1,t2,t3)\
#define snow_vertical_compose_r2r_add(s0,s1,s2,s3,t0,t1,t2,t3)\
#define snow_vertical_compose_r2r_pmulhw(s0,s1,s2,s3,t0,t1,t2,t3)\
#define snow_vertical_compose_sse2_move(s0,s1,s2,s3,t0,t1,t2,t3)\
#define snow_vertical_compose_mmx_load_add(op,r,t0,t1,t2,t3)\
#define snow_vertical_compose_mmx_load(r,t0,t1,t2,t3)\
#define snow_vertical_compose_mmx_add(r,t0,t1,t2,t3)\
#define snow_vertical_compose_mmx_store(w,s0,s1,s2,s3)\
#define snow_vertical_compose_mmx_move(s0,s1,s2,s3,t0,t1,t2,t3)\
#endif //HAVE_7REGS
#if HAVE_6REGS
#define snow_inner_add_yblock_sse2_header \
#define snow_inner_add_yblock_sse2_start_8(out_reg1, out_reg2, ptr_offset, s_offset)\
#define snow_inner_add_yblock_sse2_start_16(out_reg1, out_reg2, ptr_offset, s_offset)\
#define snow_inner_add_yblock_sse2_accum_8(ptr_offset, s_offset) \
#define snow_inner_add_yblock_sse2_accum_16(ptr_offset, s_offset) \
#define snow_inner_add_yblock_sse2_end_common1\
#define snow_inner_add_yblock_sse2_end_common2\
#define snow_inner_add_yblock_sse2_end_8\
#define snow_inner_add_yblock_sse2_end_16\
#define snow_inner_add_yblock_mmx_header \
#define snow_inner_add_yblock_mmx_start(out_reg1, out_reg2, ptr_offset, s_offset, d_offset)\
#define snow_inner_add_yblock_mmx_accum(ptr_offset, s_offset, d_offset) \
#define snow_inner_add_yblock_mmx_mix(read_offset, write_offset)\
#define snow_inner_add_yblock_mmx_end(s_step)\
#endif /* HAVE_6REGS */
#endif /* HAVE_INLINE_ASM */
#if HAVE_INLINE_ASM
#if HAVE_7REGS
#endif
#if HAVE_6REGS
#endif
#if HAVE_7REGS
#endif
#if HAVE_6REGS
#endif
#endif /* HAVE_INLINE_ASM */
