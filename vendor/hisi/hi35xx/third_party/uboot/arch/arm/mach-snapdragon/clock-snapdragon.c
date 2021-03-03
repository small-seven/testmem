#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include "clock-snapdragon.h"
#define CBCR_BRANCH_ENABLE_BIT  BIT(0)
#define CBCR_BRANCH_OFF_BIT     BIT(31)
#define BRANCH_ON_VAL (0)
#define BRANCH_NOC_FSM_ON_VAL BIT(29)
#define BRANCH_CHECK_MASK GENMASK(31, 28)
#define APPS_CMD_RGCR_UPDATE BIT(0)
#define CFG_MODE_DUAL_EDGE (0x2 << 12) /* Counter mode */
#define CFG_MASK 0x3FFF
#define CFG_DIVIDER_MASK 0x1F
