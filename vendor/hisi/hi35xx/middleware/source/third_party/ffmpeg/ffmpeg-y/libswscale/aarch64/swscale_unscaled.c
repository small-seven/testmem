#include "config.h"
#include "libswscale/swscale.h"
#include "libswscale/swscale_internal.h"
#include "libavutil/aarch64/cpu.h"
#define YUV_TO_RGB_TABLE                                                                    \
#define DECLARE_FF_YUVX_TO_RGBX_FUNCS(ifmt, ofmt)                                           \
#define DECLARE_FF_YUVX_TO_ALL_RGBX_FUNCS(yuvx)                                             \
#define DECLARE_FF_NVX_TO_RGBX_FUNCS(ifmt, ofmt)                                            \
#define DECLARE_FF_NVX_TO_ALL_RGBX_FUNCS(nvx)                                               \
#define SET_FF_NVX_TO_RGBX_FUNC(ifmt, IFMT, ofmt, OFMT, accurate_rnd) do {                  \
#define SET_FF_NVX_TO_ALL_RGBX_FUNC(nvx, NVX, accurate_rnd) do {                            \
