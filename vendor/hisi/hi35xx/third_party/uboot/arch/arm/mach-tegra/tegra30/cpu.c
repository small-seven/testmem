#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/flow.h>
#include <asm/arch/tegra.h>
#include <asm/arch-tegra/clk_rst.h>
#include <asm/arch-tegra/pmc.h>
#include <asm/arch-tegra/tegra_i2c.h>
#include "../cpu.h"
#define TPS62366A_I2C_ADDR		0xC0
#define TPS62366A_SET1_REG		0x01
#define TPS62366A_SET1_DATA		(0x4600 | TPS62366A_SET1_REG)
#define TPS62361B_I2C_ADDR		0xC0
#define TPS62361B_SET3_REG		0x03
#define TPS62361B_SET3_DATA		(0x4600 | TPS62361B_SET3_REG)
#define TPS65911_I2C_ADDR		0x5A
#define TPS65911_VDDCTRL_OP_REG		0x28
#define TPS65911_VDDCTRL_SR_REG		0x27
#define TPS65911_VDDCTRL_OP_DATA	(0x2400 | TPS65911_VDDCTRL_OP_REG)
#define TPS65911_VDDCTRL_SR_DATA	(0x0100 | TPS65911_VDDCTRL_SR_REG)
#define I2C_SEND_2_BYTES		0x0A02
#ifdef CONFIG_TEGRA_VDD_CORE_TPS62366A_SET1
#endif
#ifdef CONFIG_TEGRA_VDD_CORE_TPS62361B_SET3
#endif
