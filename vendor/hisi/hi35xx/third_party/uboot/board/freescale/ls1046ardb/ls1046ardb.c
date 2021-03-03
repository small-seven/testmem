#include <common.h>
#include <i2c.h>
#include <fdt_support.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/ppa.h>
#include <asm/arch/soc.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#include <hwconfig.h>
#include <ahci.h>
#include <mmc.h>
#include <scsi.h>
#include <fm_eth.h>
#include <fsl_csu.h>
#include <fsl_esdhc.h>
#include <power/mc34vr500_pmic.h>
#include "cpld.h"
#include <fsl_sec.h>
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_NXP_ESBC
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#ifdef CONFIG_FSL_LS_PPA
#endif
#ifdef CONFIG_HAS_FSL_XHCI_USB
#endif
#ifdef CONFIG_MISC_INIT_R
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#endif
