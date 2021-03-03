#include <init.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/boot_mode.h>
#include <asm/mach-imx/hab.h>
#define PMC0_BASE_ADDR		0x410a1000
#define PMC0_CTRL		0x28
#define PMC0_CTRL_LDOEN		BIT(31)
#define PMC0_CTRL_LDOOKDIS	BIT(30)
#define PMC0_CTRL_PMC1ON	BIT(24)
#define PMC1_BASE_ADDR		0x40400000
#define PMC1_RUN		0x8
#define PMC1_STOP		0x10
#define PMC1_VLPS		0x14
#define PMC1_LDOVL_SHIFT	16
#define PMC1_LDOVL_MASK		(0x3f << PMC1_LDOVL_SHIFT)
#define PMC1_LDOVL_900		0x1e
#define PMC1_LDOVL_950		0x23
#define PMC1_STATUS		0x20
#define PMC1_STATUS_LDOVLF	BIT(8)
#if defined(CONFIG_IMX_HAB)
#endif
#define ROM_VERSION_ADDR 0x80
#ifdef CONFIG_REVISION_TAG
#endif
#ifdef CONFIG_BOARD_POSTCLK_INIT
#endif
#define UNLOCK_WORD0 0xC520 /* 1st unlock word */
#define UNLOCK_WORD1 0xD928 /* 2nd unlock word */
#define REFRESH_WORD0 0xA602 /* 1st refresh word */
#define REFRESH_WORD1 0xB480 /* 2nd refresh word */
#if defined(CONFIG_LDO_ENABLED_MODE)
#endif
#if defined(CONFIG_LDO_ENABLED_MODE)
#endif
#ifndef CONFIG_ULP_WATCHDOG
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#define PMC0_BASE_ADDR		0x410a1000
#define PMC0_CTRL		0x28
#define PMC0_CTRL_LDOEN		BIT(31)
#endif
#define CMC_SRS_TAMPER                    (1 << 31)
#define CMC_SRS_SECURITY                  (1 << 30)
#define CMC_SRS_TZWDG                     (1 << 29)
#define CMC_SRS_JTAG_RST                  (1 << 28)
#define CMC_SRS_CORE1                     (1 << 16)
#define CMC_SRS_LOCKUP                    (1 << 15)
#define CMC_SRS_SW                        (1 << 14)
#define CMC_SRS_WDG                       (1 << 13)
#define CMC_SRS_PIN_RESET                 (1 << 8)
#define CMC_SRS_WARM                      (1 << 4)
#define CMC_SRS_HVD                       (1 << 3)
#define CMC_SRS_LVD                       (1 << 2)
#define CMC_SRS_POR                       (1 << 1)
#define CMC_SRS_WUP                       (1 << 0)
#ifdef CONFIG_ENV_IS_IN_MMC
#endif
