#include <common.h>
#include <i2c.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "../drivers/ddr/marvell/a38x/ddr3_init.h"
#include <../serdes/a38x/high_speed_env_spec.h>
#define DB_AMC_88F68XX_GPP_OUT_ENA_LOW					\
#define DB_AMC_88F68XX_GPP_OUT_ENA_MID					\
#define DB_AMC_88F68XX_GPP_OUT_VAL_LOW	(BIT(29))
#define DB_AMC_88F68XX_GPP_OUT_VAL_MID	0x0
#define DB_AMC_88F68XX_GPP_OUT_VAL_HIGH	0x0
#define DB_AMC_88F68XX_GPP_POL_LOW	0x0
#define DB_AMC_88F68XX_GPP_POL_MID	0x0
