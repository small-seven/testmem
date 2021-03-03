#include "libavutil/attributes.h"
#include "internal.h"
#include "avcodec.h"
#include "mpegvideo.h"
#include "vc1.h"
#include "vc1data.h"
#include "wmv2data.h"
#include "unary.h"
#include "simple_idct.h"
#define INIT_LUT(lumscale, lumshift, luty, lutuv, chain) do {                 \
#define ROTATE(DEF, L, N, C, A) do {                          \
