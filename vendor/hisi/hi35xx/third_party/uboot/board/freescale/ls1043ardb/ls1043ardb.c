#include <common.h>
#include <i2c.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/arch/soc.h>
#include <asm/arch-fsl-layerscape/fsl_icid.h>
#include <fdt_support.h>
#include <hwconfig.h>
#include <ahci.h>
#include <mmc.h>
#include <scsi.h>
#include <fm_eth.h>
#include <fsl_esdhc.h>
#include <fsl_ifc.h>
#include <fsl_sec.h>
#include "cpld.h"
#ifdef CONFIG_U_QE
#include <fsl_qe.h>
#endif
#include <asm/arch/ppa.h>
#ifdef CONFIG_TFABOOT
#endif
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_TFABOOT
#endif
#ifndef CONFIG_SD_BOOT
#endif
#ifdef CONFIG_TFABOOT
#endif
#ifdef CONFIG_SD_BOOT
#else
#endif
#ifdef CONFIG_TFABOOT
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A010315
#endif
#ifdef CONFIG_FSL_IFC
#endif
#ifdef CONFIG_NXP_ESBC
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#ifdef CONFIG_FSL_LS_PPA
#endif
#ifdef CONFIG_U_QE
#endif
#ifdef CONFIG_HAS_FSL_XHCI_USB
#endif
#if defined(CONFIG_MISC_INIT_R)
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#ifdef CONFIG_HAS_FSL_XHCI_USB
#endif
#endif
