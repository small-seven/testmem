#include <common.h>
#include <edid.h>
#include <env.h>
#include <errno.h>
#include <linux/ctype.h>
#include "videomodes.h"
#ifndef CONFIG_VIDEO_STD_TIMINGS
#else
#endif
#define GET_OPTION(name,var)				\
