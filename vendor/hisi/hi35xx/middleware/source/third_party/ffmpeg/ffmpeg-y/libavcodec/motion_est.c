#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "avcodec.h"
#include "internal.h"
#include "mathops.h"
#include "motion_est.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#define P_LEFT P[1]
#define P_TOP P[2]
#define P_TOPRIGHT P[3]
#define P_MEDIAN P[4]
#define P_MV1 P[9]
#define ME_MAP_SHIFT 3
#define ME_MAP_MV_BITS 11
typedef struct Minima{
    int height;
    int x, y;
    int checked;
}Minima;
#define FLAG_QPEL   1 //must be 1
#define FLAG_CHROMA 2
#define FLAG_DIRECT 4
#include "motion_est_template.c"
#define CHECK_SAD_HALF_MV(suffix, x, y) \
#define HASH(fx,fy,bx,by) ((fx)+17*(fy)+63*(bx)+117*(by))
#define HASH8(fx,fy,bx,by) ((uint8_t)HASH(fx,fy,bx,by))
#define CHECK_BIDIR(fx,fy,bx,by)\
#define CHECK_BIDIR2(a,b,c,d)\
