#include <common.h>
#include <command.h>
#include "hi_common_vo.h"
#include "vo.h"
#if CONFIG_HI_HDMI_SUPPORT
#include "hi_hdmi.h"
#endif
#define CFG_MAXARGS_SETVOBG 3
#define CFG_MAXARGS_STARTVO 4
#define CFG_MAXARGS_STOPVO 2
#define CFG_MAXARGS_STARTVL 8
#define CFG_MAXARGS_STOPVL 2
#define CFG_MAXARGS_STARTGX 9
#define CFG_MAXARGS_STOPGX 2
#define CMD_VO_ARGS_BASE10 10
#define CMD_VO_ARGS_BASE16 16
#define CMD_VO_ARGS_BASE_ALL 0
#define INSUFFICIENT_PARAM_STR "insufficient parameter or operation not permitted!\n"
#define VO_DEV_MAX_NUM 3
#if CONFIG_HI_HDMI_SUPPORT
#endif
#if CONFIG_HI_HDMI_SUPPORT
#endif
#if CONFIG_HI_HDMI_SUPPORT
#endif
#if ((defined(CHIP_HI3531DV200)) || (defined(CHIP_HI3535AV100)))
#define USAGE_DEV_STRING                                                           \
#define USAGE_INTF_STRING                                                          \
#define USAGE_GX_STRING                           \
#define USAGE_VL_STRING                           \
#elif (defined(CHIP_HI3521DV200))
#define USAGE_DEV_STRING                                                           \
#define USAGE_INTF_STRING                                                          \
#define USAGE_GX_STRING                           \
#define USAGE_VL_STRING                           \
#elif (defined(CHIP_HI3520DV500))
#define USAGE_DEV_STRING                                                           \
#define USAGE_INTF_STRING                                                          \
#define USAGE_GX_STRING                           \
#define USAGE_VL_STRING                           \
#else
#define USAGE_DEV_STRING                          \
#define USAGE_INTF_STRING                                                          \
#define USAGE_GX_STRING                            \
#define USAGE_VL_STRING                            \
#endif
#define USAGE_GX_TYPE                              \
#define USAGE_START_VO                                                             \
#define USAGE_STOP_VO                             \
#define USAGE_START_GX                            \
#define USAGE_STOP_GX                             \
#define USAGE_START_VL                            \
#define USAGE_STOP_VL                             \
#define USAGE_SET_VO_BG                           \
