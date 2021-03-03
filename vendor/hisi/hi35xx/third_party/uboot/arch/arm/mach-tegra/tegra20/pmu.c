#include <common.h>
#include <i2c.h>
#include <tps6586x.h>
#include <asm/io.h>
#include <asm/arch/tegra.h>
#include <asm/arch-tegra/ap.h>
#include <asm/arch-tegra/tegra_i2c.h>
#include <asm/arch-tegra/sys_proto.h>
#define VDD_CORE_NOMINAL_T25	0x17	/* 1.3v */
#define VDD_CPU_NOMINAL_T25	0x10	/* 1.125v */
#define VDD_CORE_NOMINAL_T20	0x16	/* 1.275v */
#define VDD_CPU_NOMINAL_T20	0x0f	/* 1.1v */
#define VDD_RELATION		0x02	/*  50mv */
#define VDD_TRANSITION_STEP	0x06	/* 150mv */
#define VDD_TRANSITION_RATE	0x06	/* 3.52mv/us */
#define PMI_I2C_ADDRESS	0x34	/* chip requires this address */
