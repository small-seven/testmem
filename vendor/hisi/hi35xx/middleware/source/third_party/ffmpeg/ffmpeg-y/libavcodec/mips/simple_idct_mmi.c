#include "idctdsp_mips.h"
#include "constants.h"
#include "libavutil/mips/asmdefs.h"
#include "libavutil/mips/mmiutils.h"
#define W1  22725  //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W2  21407  //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W3  19266  //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W4  16383  //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W5  12873  //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W6  8867   //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W7  4520   //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define ROW_SHIFT 11
#define COL_SHIFT 20
#define DC_SHIFT 3
#define IDCT_ROW_COND_DC(src1, src2)                                  \
#define IDCT_COL_CASE1(src, out1, out2)                               \
#define IDCT_COL_CASE2(src1, src2, out1, out2)                        \
