#include <common.h>
#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/ddrmc-vf610.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux-vf610.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <env.h>
#include <fdt_support.h>
#include <fsl_dcu_fb.h>
#include <g_dnl.h>
#include <jffs2/load_kernel.h>
#include <mtd_node.h>
#include <usb.h>
#include "../common/tdx-common.h"
#define PTC0_GPIO_45		45
#ifdef CONFIG_VYBRID_GPIO
#endif
#ifdef CONFIG_VIDEO_FSL_DCU_FB
#endif
#ifdef CONFIG_FSL_DSPI
#endif
#ifdef CONFIG_USB_EHCI_VF
#endif
#ifdef CONFIG_VIDEO_FSL_DCU_FB
#endif
#ifdef CONFIG_VYBRID_GPIO
#endif
#ifdef CONFIG_VIDEO_FSL_DCU_FB
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#endif /* CONFIG_BOARD_LATE_INIT */
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#ifndef CONFIG_DM_VIDEO
#endif
#ifdef CONFIG_FDT_FIXUP_PARTITIONS
#endif
#if defined(CONFIG_VIDEO_FSL_DCU_FB) && !defined(CONFIG_DM_VIDEO)
#endif
#endif
