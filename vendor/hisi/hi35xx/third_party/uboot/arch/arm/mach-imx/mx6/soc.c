#include <common.h>
#include <init.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/bootm.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/dma.h>
#include <asm/mach-imx/hab.h>
#include <stdbool.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/crm_regs.h>
#include <dm.h>
#include <imx_thermal.h>
#include <mmc.h>
#if defined(CONFIG_IMX_THERMAL)
#endif
#if defined(CONFIG_IMX_HAB)
#endif
#define OCOTP_CFG3_SPEED_SHIFT	16
#define OCOTP_CFG3_SPEED_800MHZ	0
#define OCOTP_CFG3_SPEED_850MHZ	1
#define OCOTP_CFG3_SPEED_1GHZ	2
#define OCOTP_CFG3_SPEED_1P2GHZ	3
#define OCOTP_CFG3_SPEED_528MHZ 1
#define OCOTP_CFG3_SPEED_696MHZ 2
#define OCOTP_CFG3_SPEED_792MHZ 2
#define OCOTP_CFG3_SPEED_900MHZ 3
#define OCOTP_MEM0_TEMP_SHIFT          6
#ifdef CONFIG_REVISION_TAG
#endif
#define OCOTP_MEM0_REFTOP_TRIM_SHIFT          8
#if defined(CONFIG_MX6Q) || defined(CONFIG_MX6QDL)
#endif
#if defined(CONFIG_MX6Q) || defined(CONFIG_MX6QDL)
#endif
#ifdef CONFIG_ENV_IS_IN_MMC
#ifdef CONFIG_SYS_MMC_ENV_PART
#endif
#endif
#ifndef CONFIG_SPL_BUILD
#if defined(CONFIG_MX6UL) || defined(CONFIG_MX6ULL)
#else
#endif
#endif
#ifndef CONFIG_SPL_BUILD
#if defined(CONFIG_VIDEO_MXS) && !defined(CONFIG_DM_VIDEO)
#endif
#endif
#ifdef CONFIG_IMX_HDMI
#endif
