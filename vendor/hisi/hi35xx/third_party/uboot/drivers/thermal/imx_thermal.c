#include <config.h>
#include <common.h>
#include <div64.h>
#include <fuse.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <linux/math64.h>
#include <thermal.h>
#include <imx_thermal.h>
#define TEMPERATURE_HOT_DELTA   5 /* CPU maxT - 5C */
#define FACTOR0			10000000
#define FACTOR1			15423
#define FACTOR2			4148468
#define OFFSET			3580661
#define MEASURE_FREQ		327
#define TEMPERATURE_MIN         -40
#define TEMPERATURE_HOT         85
#define TEMPERATURE_MAX         125
#define TEMPSENSE0_TEMP_CNT_SHIFT	8
#define TEMPSENSE0_TEMP_CNT_MASK	(0xfff << TEMPSENSE0_TEMP_CNT_SHIFT)
#define TEMPSENSE0_FINISHED		(1 << 2)
#define TEMPSENSE0_MEASURE_TEMP		(1 << 1)
#define TEMPSENSE0_POWER_DOWN		(1 << 0)
#define MISC0_REFTOP_SELBIASOFF		(1 << 3)
#define TEMPSENSE1_MEASURE_FREQ		0xffff
#if defined(CONFIG_MX6)
#elif defined(CONFIG_MX7)
#endif
