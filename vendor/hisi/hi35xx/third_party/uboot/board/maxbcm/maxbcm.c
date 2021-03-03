#include <common.h>
#include <miiphy.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <linux/mbus.h>
#include "../drivers/ddr/marvell/axp/ddr3_hw_training.h"
#include "../arch/arm/mach-mvebu/serdes/axp/high_speed_env_spec.h"
#define DEV_CS0_BASE		0xe0000000
#define DEV_CS1_BASE		0xe1000000
#define DEV_CS2_BASE		0xe2000000
#define DEV_CS3_BASE		0xe3000000
