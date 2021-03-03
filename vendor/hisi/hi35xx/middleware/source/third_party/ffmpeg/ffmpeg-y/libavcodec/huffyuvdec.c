#define UNCHECKED_BITSTREAM_READER 1
#include "avcodec.h"
#include "get_bits.h"
#include "huffyuv.h"
#include "huffyuvdsp.h"
#include "lossless_videodsp.h"
#include "thread.h"
#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#define classic_shift_luma_table_size 42
#define classic_shift_chroma_table_size 59
#if HAVE_THREADS
#endif
#define VLC_INTERN(dst, table, gb, name, bits, max_depth)   \
#define GET_VLC_DUAL(dst0, dst1, name, gb, dtable, table1, table2,  \
#define OP8bits(dst0, dst1, code) dst0 = code>>8; dst1 = code
#define READ_2PIX(dst0, dst1, plane1)                                   \
#define READ_2PIX_PLANE(dst0, dst1, plane, OP) \
#define OP14bits(dst0, dst1, code) dst0 = code>>8; dst1 = sign_extend(code, 8)
#define READ_2PIX_PLANE16(dst0, dst1, plane){\
#if CONFIG_FFVHUFF_DECODER
#endif /* CONFIG_FFVHUFF_DECODER */
#if CONFIG_HYMT_DECODER
#endif /* CONFIG_HYMT_DECODER */
