#include <bootm.h>
#include <common.h>
#include <netdev.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/crm_regs.h>
#include <asm/mach-imx/boot_mode.h>
#include <imx_thermal.h>
#include <ipu_pixfmt.h>
#include <thermal.h>
#include <sata.h>
#ifdef CONFIG_FSL_ESDHC_IMX
#include <fsl_esdhc_imx.h>
#endif
#if !defined(CONFIG_SPL_BUILD)
#endif
#if defined(CONFIG_DISPLAY_CPUINFO) && !defined(CONFIG_SPL_BUILD)
#ifdef	CONFIG_MX7
#else
#endif
#ifdef CONFIG_MX7
#elif defined(CONFIG_IMX8M)
#else
#endif
#endif
#if defined(CONFIG_DISPLAY_CPUINFO) && !defined(CONFIG_SPL_BUILD)
#if defined(CONFIG_IMX_THERMAL)
#else
#endif
#if defined(CONFIG_IMX_THERMAL)
#endif
#endif
#if defined(CONFIG_FEC_MXC)
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#if !(defined(CONFIG_MX7) || defined(CONFIG_IMX8M))
#endif
#if defined(CONFIG_PCIE_IMX) && !CONFIG_IS_ENABLED(DM_PCI)
#endif
#if defined(CONFIG_SATA)
#if defined(CONFIG_MX6)
#endif
#endif
#if defined(CONFIG_VIDEO_IPUV3)
#endif
#if defined(CONFIG_VIDEO_MXS) && !defined(CONFIG_DM_VIDEO)
#endif
#ifndef CONFIG_IMX8M
#endif
#if defined(CONFIG_MX7) || defined(CONFIG_IMX8M)
#define OCOTP_TESTER3_SPEED_SHIFT	8
#define OCOTP_TESTER3_TEMP_SHIFT	6
#endif
#if defined(CONFIG_MX7) || defined(CONFIG_IMX8MQ) || defined(CONFIG_IMX8MM)
#ifdef CONFIG_IMX8M
#endif
#endif
#ifdef CONFIG_NXP_BOARD_REVISION
#endif
