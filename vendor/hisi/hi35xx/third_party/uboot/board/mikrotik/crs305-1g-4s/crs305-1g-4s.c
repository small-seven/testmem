#include <common.h>
#include <i2c.h>
#include <asm/gpio.h>
#include <linux/mbus.h>
#include <linux/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#define DB_DX_AC3_GPP_OUT_ENA_LOW	(~(BIT(0) | BIT(2) | BIT(3) | BIT(4) \
#define DB_DX_AC3_GPP_OUT_ENA_MID	(~(0))
#define DB_DX_AC3_GPP_OUT_VAL_LOW	(BIT(0) | BIT(2) | BIT(3) | BIT(4) \
#define DB_DX_AC3_GPP_OUT_VAL_MID	0x0
#define DB_DX_AC3_GPP_POL_LOW		0x0
#define DB_DX_AC3_GPP_POL_MID		0x0
