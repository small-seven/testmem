#include <common.h>
#include <dm.h>
#include <errno.h>
#include <i2c.h>
#include <edid.h>
#include <video_bridge.h>
#include "../anx98xx-edp.h"
#define DP_MAX_LINK_RATE		0x001
#define DP_MAX_LANE_COUNT		0x002
#define DP_MAX_LANE_COUNT_MASK		0x1f
