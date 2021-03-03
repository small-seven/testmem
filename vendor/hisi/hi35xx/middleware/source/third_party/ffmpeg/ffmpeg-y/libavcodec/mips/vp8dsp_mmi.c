#include "vp8dsp_mips.h"
#include "constants.h"
#include "libavutil/mips/mmiutils.h"
#define DECLARE_DOUBLE_1            double db_1
#define DECLARE_DOUBLE_2            double db_2
#define DECLARE_UINT32_T            uint32_t  it_1
#define RESTRICT_ASM_DOUBLE_1       [db_1]"=&f"(db_1)
#define RESTRICT_ASM_DOUBLE_2       [db_2]"=&f"(db_2)
#define RESTRICT_ASM_UINT32_T       [it_1]"=&r"(it_1)
#define MMI_PCMPGTUB(dst, src1, src2)                                       \
#define MMI_BTOH(dst_l, dst_r, src)                                         \
#define MMI_VP8_LOOP_FILTER                                                 \
#define PUT_VP8_EPEL4_H6_MMI(src, dst)                                      \
#define PUT_VP8_EPEL4_H4_MMI(src, dst)                                      \
#define PUT_VP8_EPEL4_V6_MMI(src, src1, dst, srcstride)                     \
#define PUT_VP8_EPEL4_V4_MMI(src, src1, dst, srcstride)                     \
#define PUT_VP8_EPEL8_H6_MMI(src, dst)                                      \
#define PUT_VP8_EPEL8_H4_MMI(src, dst)                                      \
#define PUT_VP8_EPEL8_V6_MMI(src, src1, dst, srcstride)                     \
#define PUT_VP8_EPEL8_V4_MMI(src, src1, dst, srcstride)                     \
#define PUT_VP8_BILINEAR8_H_MMI(src, dst)                                   \
#define PUT_VP8_BILINEAR4_H_MMI(src, dst)                                   \
#define PUT_VP8_BILINEAR8_V_MMI(src, src1, dst, sstride)                    \
#define PUT_VP8_BILINEAR4_V_MMI(src, src1, dst, sstride)                    \
#if 0
#define FILTER_6TAP(src, F, stride)                                           \
#define FILTER_4TAP(src, F, stride)                                           \
#define MUL_20091(a) ((((a) * 20091) >> 16) + (a))
#define MUL_35468(a)  (((a) * 35468) >> 16)
#endif
#define clip_int8(n) (cm[(n) + 0x80] - 0x80)
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
#if 1
#else
#endif
