#include <common.h>
#include <clk.h>
#include <display.h>
#include <dm.h>
#include <errno.h>
#include "axi.h"
#include "logicore_dp_dpcd.h"
#include "logicore_dp_tx.h"
#include "logicore_dp_tx_regif.h"
#define S_AXI_CLK_DEFAULT 100000000
#define PHY_CLOCK_SELECT_DEFAULT PHY_CLOCK_SELECT_540GBPS
#define MAXIMUM_VS_LEVEL 3
#define MAXIMUM_PE_LEVEL 3
#define AUX_MAX_DEFER_COUNT 50
#define AUX_MAX_TIMEOUT_COUNT 50
#define IS_CONNECTED_MAX_TIMEOUT_COUNT 50
