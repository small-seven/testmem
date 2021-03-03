#include <common.h>
#include <miiphy.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <linux/mbus.h>
#include "../drivers/ddr/marvell/axp/ddr3_hw_training.h"
#include "../arch/arm/mach-mvebu/serdes/axp/high_speed_env_spec.h"
#include "../arch/arm/mach-mvebu/serdes/axp/board_env_spec.h"
#define DS414_GPP_OUT_VAL_LOW		(BIT(25) | BIT(30))
#define DS414_GPP_OUT_VAL_MID		(BIT(10) | BIT(15))
#define DS414_GPP_OUT_VAL_HIGH		(0)
#define DS414_GPP_OUT_POL_LOW		(0)
#define DS414_GPP_OUT_POL_MID		(0)
#define DS414_GPP_OUT_POL_HIGH		(0)
#define DS414_GPP_OUT_ENA_LOW		(~(BIT(25) | BIT(30)))
#define DS414_GPP_OUT_ENA_MID		(~(BIT(10) | BIT(12) | \
#define DS414_GPP_OUT_ENA_HIGH		(~0)
