#include <common.h>
#include <ahci.h>
#include <cpu_func.h>
#include <linux/mbus.h>
#include <asm/io.h>
#include <asm/pl310.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <sdhci.h>
#define DDR_BASE_CS_OFF(n)	(0x0000 + ((n) << 3))
#define DDR_SIZE_CS_OFF(n)	(0x0004 + ((n) << 3))
#ifdef CONFIG_ARMADA_MSYS
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#if defined(CONFIG_ARMADA_375)
#elif defined(CONFIG_ARMADA_38X)
#elif defined(CONFIG_ARMADA_MSYS)
#else
#endif
#if defined(CONFIG_ARMADA_375) || defined(CONFIG_ARMADA_MSYS)
#else
#endif
#if defined(SAR2_CPU_FREQ_MASK)
#endif
#if defined(CONFIG_ARMADA_375) || defined(CONFIG_ARMADA_38X) || defined(CONFIG_ARMADA_MSYS)
#else
#endif
#endif /* CONFIG_DISPLAY_CPUINFO */
#ifdef CONFIG_ARCH_CPU_INIT
#define MV_USB_PHY_BASE			(MVEBU_AXP_USB_BASE + 0x800)
#define MV_USB_PHY_PLL_REG(reg)		(MV_USB_PHY_BASE | (((reg) & 0xF) << 2))
#define MV_USB_X3_BASE(addr)		(MVEBU_AXP_USB_BASE | BIT(11) | \
#define MV_USB_X3_PHY_CHANNEL(dev, reg)	(MV_USB_X3_BASE((dev) + 1) |	\
#endif /* CONFIG_ARCH_CPU_INIT */
#if defined(CONFIG_ARCH_MISC_INIT)
#endif /* CONFIG_ARCH_MISC_INIT */
#if defined(CONFIG_MMC_SDHCI_MV) && !defined(CONFIG_DM_MMC)
#endif
#define AHCI_VENDOR_SPECIFIC_0_ADDR	0xa0
#define AHCI_VENDOR_SPECIFIC_0_DATA	0xa4
#define AHCI_WINDOW_CTRL(win)		(0x60 + ((win) << 4))
#define AHCI_WINDOW_BASE(win)		(0x64 + ((win) << 4))
#define AHCI_WINDOW_SIZE(win)		(0x68 + ((win) << 4))
#ifdef CONFIG_SCSI_AHCI_PLAT
#endif
#ifdef CONFIG_USB_XHCI_MVEBU
#define USB3_MAX_WINDOWS        4
#define USB3_WIN_CTRL(w)        (0x0 + ((w) * 8))
#define USB3_WIN_BASE(w)        (0x4 + ((w) * 8))
#endif
