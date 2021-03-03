#include <common.h>
#include <clk.h>
#include <dm.h>
#include <asm/io.h>
#include <linux/iopoll.h>
#include <linux/kernel.h>
#include <power/regulator.h>
#define STM32_VREFBUF_CSR		0x00
#define STM32_VRS			GENMASK(6, 4)
#define STM32_VRS_SHIFT			4
#define STM32_VRR			BIT(3)
#define STM32_HIZ			BIT(1)
#define STM32_ENVR			BIT(0)
