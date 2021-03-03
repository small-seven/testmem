#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "golomb.h"
#include "rv34.h"
#include "rv40vlc2.h"
#include "rv40data.h"
#define MASK_CUR          0x0001
#define MASK_RIGHT        0x0008
#define MASK_BOTTOM       0x0010
#define MASK_TOP          0x1000
#define MASK_Y_TOP_ROW    0x000F
#define MASK_Y_LAST_ROW   0xF000
#define MASK_Y_LEFT_COL   0x1111
#define MASK_Y_RIGHT_COL  0x8888
#define MASK_C_TOP_ROW    0x0003
#define MASK_C_LAST_ROW   0x000C
#define MASK_C_LEFT_COL   0x0005
#define MASK_C_RIGHT_COL  0x000A
