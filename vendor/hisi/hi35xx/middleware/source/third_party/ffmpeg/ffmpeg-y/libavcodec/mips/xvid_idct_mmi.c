#include "idctdsp_mips.h"
#include "xvididct_mips.h"
#define BITS_INV_ACC    5                           // 4 or 5 for IEEE
#define SHIFT_INV_ROW   (16 - BITS_INV_ACC)         //11
#define SHIFT_INV_COL   (1 + BITS_INV_ACC)          //6
#define RND_INV_ROW     (1024 * (6 - BITS_INV_ACC))
#define RND_INV_COL     (16 * (BITS_INV_ACC - 3))
#define RND_INV_CORR    (RND_INV_COL - 1)
#define BITS_FRW_ACC    3                           // 2 or 3 for accuracy
#define SHIFT_FRW_COL   BITS_FRW_ACC
#define SHIFT_FRW_ROW   (BITS_FRW_ACC + 17)
#define RND_FRW_ROW     (262144*(BITS_FRW_ACC - 1))
#define DCT_8_INV_ROW_MMI(A1,A2,A3,A4)                                      \
#define DCT_8_INV_COL(A1,A2)                                                \
