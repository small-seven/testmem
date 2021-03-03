#include <common.h>
#include <dm.h>
#include <init.h>
#include <miiphy.h>
#include <tpm-v1.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm-generic/gpio.h>
#include "../drivers/ddr/marvell/a38x/ddr3_init.h"
#include "../arch/arm/mach-mvebu/serdes/a38x/high_speed_env_spec.h"
#include "keyprogram.h"
#include "dt_helpers.h"
#include "hydra.h"
#include "ihs_phys.h"
#define DB_GP_88F68XX_GPP_OUT_ENA_LOW	0x7fffffff
#define DB_GP_88F68XX_GPP_OUT_ENA_MID	0xffffefff
#define DB_GP_88F68XX_GPP_OUT_VAL_LOW	0x0
#define DB_GP_88F68XX_GPP_OUT_VAL_MID	0x00001000
#define DB_GP_88F68XX_GPP_POL_LOW	0x0
#define DB_GP_88F68XX_GPP_POL_MID	0x0
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
