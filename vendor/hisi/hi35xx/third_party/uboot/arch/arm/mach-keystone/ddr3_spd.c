#include <common.h>
#include <i2c.h>
#include <ddr_spd.h>
#include <asm/arch/ddr3.h>
#include <asm/arch/hardware.h>
#define DUMP_DDR_CONFIG			0	/* set to 1 to debug */
#define debug_ddr_cfg(fmt, args...)					\
#define TEMP NORMAL_TEMP
#define VBUS_CLKPERIOD 1.875 /* Corresponds to vbus=533MHz, */
#define PLLGS_VAL	(4000.0 / VBUS_CLKPERIOD) /* 4 us */
#define PLLPD_VAL	(1000.0 / VBUS_CLKPERIOD) /* 1 us */
#define PLLLOCK_VAL	(100000.0 / VBUS_CLKPERIOD) /* 100 us */
#define PLLRST_VAL	(9000.0 / VBUS_CLKPERIOD) /* 9 us */
#define PHYRST_VAL	0x10
#define DDR_TERM RZQ_4_TERM
#define SDRAM_DRIVE RZQ_7_IMP
#define DYN_ODT ODT_DISABLE
#ifndef CONFIG_DM_I2C
#else
#endif
