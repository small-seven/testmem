#include <stdio.h>
#include <stdint.h>
#include "../pngpriv.h"
#ifdef PNG_READ_SUPPORTED
#if PNG_MIPS_MSA_IMPLEMENTATION == 1 /* intrinsics code from pngpriv.h */
#include <msa.h>
#define png_ptr(type,pointer) png_aligncast(type *,pointer)
#define png_ptrc(type,pointer) png_aligncastconst(const type *,pointer)
#define png_ldr(type,pointer)\
#if PNG_MIPS_MSA_OPT > 0
#ifdef CLANG_BUILD
#else
#if (__mips_isa_rev >= 6)
#else  // !(__mips_isa_rev >= 6)
#endif  // (__mips_isa_rev >= 6)
#endif
#define LD_B(RTYPE, psrc) *((RTYPE *) (psrc))
#define LD_UB(...) LD_B(v16u8, __VA_ARGS__)
#define LD_B2(RTYPE, psrc, stride, out0, out1)  \
#define LD_UB2(...) LD_B2(v16u8, __VA_ARGS__)
#define LD_B4(RTYPE, psrc, stride, out0, out1, out2, out3)   \
#define LD_UB4(...) LD_B4(v16u8, __VA_ARGS__)
#define ST_B(RTYPE, in, pdst) *((RTYPE *) (pdst)) = (in)
#define ST_UB(...) ST_B(v16u8, __VA_ARGS__)
#define ST_B2(RTYPE, in0, in1, pdst, stride)  \
#define ST_UB2(...) ST_B2(v16u8, __VA_ARGS__)
#define ST_B4(RTYPE, in0, in1, in2, in3, pdst, stride)    \
#define ST_UB4(...) ST_B4(v16u8, __VA_ARGS__)
#define ADD2(in0, in1, in2, in3, out0, out1)  \
#define ADD3(in0, in1, in2, in3, in4, in5,  \
#define ADD4(in0, in1, in2, in3, in4, in5, in6, in7,  \
#define ILVR_B2(RTYPE, in0, in1, in2, in3, out0, out1)      \
#define ILVR_B2_SH(...) ILVR_B2(v8i16, __VA_ARGS__)
#define HSUB_UB2(RTYPE, in0, in1, out0, out1)                 \
#define HSUB_UB2_SH(...) HSUB_UB2(v8i16, __VA_ARGS__)
#define SLDI_B2_0(RTYPE, in0, in1, out0, out1, slide_val)                 \
#define SLDI_B2_0_UB(...) SLDI_B2_0(v16u8, __VA_ARGS__)
#define SLDI_B3_0(RTYPE, in0, in1, in2, out0, out1, out2,  slide_val)     \
#define SLDI_B3_0_UB(...) SLDI_B3_0(v16u8, __VA_ARGS__)
#define ILVEV_W2(RTYPE, in0, in1, in2, in3, out0, out1)      \
#define ILVEV_W2_UB(...) ILVEV_W2(v16u8, __VA_ARGS__)
#define ADD_ABS_H3(RTYPE, in0, in1, in2, out0, out1, out2)  \
#define ADD_ABS_H3_SH(...) ADD_ABS_H3(v8i16, __VA_ARGS__)
#define VSHF_B2(RTYPE, in0, in1, in2, in3, mask0, mask1, out0, out1)       \
#define VSHF_B2_UB(...) VSHF_B2(v16u8, __VA_ARGS__)
#define CMP_AND_SELECT(inp0, inp1, inp2, inp3, inp4, inp5, out0)              \
#endif /* PNG_MIPS_MSA_OPT > 0 */
#endif /* PNG_MIPS_MSA_IMPLEMENTATION == 1 (intrinsics) */
#endif /* READ */
