#include <errno.h>
#include <common.h>
#include <asm/ti-common/keystone_serdes.h>
#define SERDES_CMU_REGS(x)		(0x0000 + (0x0c00 * (x)))
#define SERDES_LANE_REGS(x)		(0x0200 + (0x200 * (x)))
#define SERDES_COMLANE_REGS		0x0a00
#define SERDES_WIZ_REGS			0x1fc0
#define SERDES_CMU_REG_000(x)		(SERDES_CMU_REGS(x) + 0x000)
#define SERDES_CMU_REG_010(x)		(SERDES_CMU_REGS(x) + 0x010)
#define SERDES_COMLANE_REG_000		(SERDES_COMLANE_REGS + 0x000)
#define SERDES_LANE_REG_000(x)		(SERDES_LANE_REGS(x) + 0x000)
#define SERDES_LANE_REG_028(x)		(SERDES_LANE_REGS(x) + 0x028)
#define SERDES_LANE_CTL_STATUS_REG(x)	(SERDES_WIZ_REGS + 0x0020 + (4 * (x)))
#define SERDES_PLL_CTL_REG		(SERDES_WIZ_REGS + 0x0034)
#define SERDES_RESET			BIT(28)
#define SERDES_LANE_RESET		BIT(29)
#define SERDES_LANE_LOOPBACK		BIT(30)
#define SERDES_LANE_EN_VAL(x, y, z)	(x[y] | (z << 26) | (z << 10))
#define SERDES_CMU_CFG_NUM		5
#define SERDES_COMLANE_CFG_NUM		10
#define SERDES_LANE_CFG_NUM		10
