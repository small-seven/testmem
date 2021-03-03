#include "libavutil/mips/generic_macros_msa.h"
#include "qpeldsp_mips.h"
#define APPLY_HORIZ_QPEL_FILTER(inp0, inp1, mask, coef0, coef1, coef2)  \
#define APPLY_HORIZ_QPEL_FILTER_8BYTE(inp0, inp1,                       \
#define APPLY_HORIZ_QPEL_FILTER_8BYTE_1ROW(inp0,                        \
#define APPLY_HORIZ_QPEL_NO_ROUND_FILTER_8BYTE_1ROW(inp0, mask0, mask1,   \
#define APPLY_HORIZ_QPEL_NO_ROUND_FILTER(inp0, inp1, mask,              \
#define APPLY_HORIZ_QPEL_NO_ROUND_FILTER_8BYTE(inp0, inp1,                  \
#define APPLY_VERT_QPEL_FILTER(inp0, inp1, inp2, inp3,                  \
#define APPLY_VERT_QPEL_FILTER_8BYTE(inp00, inp01, inp02, inp03,        \
#define APPLY_VERT_QPEL_NO_ROUND_FILTER(inp0, inp1, inp2, inp3,         \
#define APPLY_VERT_QPEL_NO_ROUND_FILTER_8BYTE(inp00, inp01, inp02, inp03,  \
