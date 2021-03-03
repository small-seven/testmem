#include <common.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#define ETH_PHY_CTRL_REG		0
#define ETH_PHY_CTRL_POWER_DOWN_BIT	11
#define ETH_PHY_CTRL_POWER_DOWN_MASK	(1 << ETH_PHY_CTRL_POWER_DOWN_BIT)
#define RD_78460_GP_GPP_OUT_ENA_LOW	(~(BIT(21) | BIT(20)))
#define RD_78460_GP_GPP_OUT_ENA_MID	(~(BIT(26) | BIT(27)))
#define RD_78460_GP_GPP_OUT_ENA_HIGH	(~(0x0))
#define RD_78460_GP_GPP_OUT_VAL_LOW	(BIT(21) | BIT(20))
#define RD_78460_GP_GPP_OUT_VAL_MID	(BIT(26) | BIT(27))
#define RD_78460_GP_GPP_OUT_VAL_HIGH	0x0
