#include <common.h>
#include <div64.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#ifdef CONFIG_MXC_OCOTP
#endif
#ifdef CONFIG_NAND_MXS
#if defined(CONFIG_MX6SX)
#else
#endif
#endif
#if defined(CONFIG_FEC_MXC) && !defined(CONFIG_MX6SX)
#endif
#ifdef CONFIG_MXC_UART
#endif
#ifdef CONFIG_MMC
#endif
#ifdef CONFIG_SYS_I2C_MXC
#endif
#if defined(CONFIG_VIDEO_MXS)
#endif
#ifdef CONFIG_FSL_QSPI
#endif
#ifdef CONFIG_FEC_MXC
#ifdef CONFIG_MX6SX
#endif
#endif
#if defined(CONFIG_SATA) || defined(CONFIG_PCIE_IMX)
#endif
#ifdef CONFIG_SATA
#endif
#ifdef CONFIG_PCIE_IMX
#define ANADIG_ANA_MISC1_LVDSCLK1_IBEN		(1 << 12)
#define ANADIG_ANA_MISC1_LVDSCLK1_OBEN		(1 << 10)
#define ANADIG_ANA_MISC1_LVDS1_CLK_SEL_MASK	0x0000001F
#define ANADIG_ANA_MISC1_LVDS1_CLK_SEL_PCIE_REF	0xa
#define ANADIG_ANA_MISC1_LVDS1_CLK_SEL_SATA_REF	0xb
#ifdef CONFIG_SATA
#endif
#endif
#ifdef CONFIG_IMX_HAB
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifndef CONFIG_MX6SX
#endif
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_MXC_SPI
#endif
#if defined(CONFIG_MX6Q) || defined(CONFIG_MX6D) || defined(CONFIG_MX6DL) || \
#endif
#endif
