#include <common.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/dma.h>
#include <asm/mach-imx/hab.h>
#include <asm/mach-imx/rdc-sema.h>
#include <asm/arch/imx-rdc.h>
#include <asm/arch/crm_regs.h>
#include <dm.h>
#include <env.h>
#include <imx_thermal.h>
#include <fsl_sec.h>
#include <asm/setup.h>
#define IOMUXC_GPR1		0x4
#define BM_IOMUXC_GPR1_IRQ	0x1000
#define GPC_LPCR_A7_BSC		0x0
#define GPC_LPCR_M4		0x8
#define GPC_SLPCR		0x14
#define GPC_PGC_ACK_SEL_A7	0x24
#define GPC_IMR1_CORE0		0x30
#define GPC_IMR1_CORE1		0x40
#define GPC_IMR1_M4		0x50
#define GPC_PGC_CPU_MAPPING	0xec
#define GPC_PGC_C0_PUPSCR	0x804
#define GPC_PGC_SCU_TIMING	0x890
#define GPC_PGC_C1_PUPSCR	0x844
#define BM_LPCR_A7_BSC_IRQ_SRC_A7_WAKEUP	0x70000000
#define BM_LPCR_A7_BSC_CPU_CLK_ON_LPM		0x4000
#define BM_LPCR_M4_MASK_DSM_TRIGGER		0x80000000
#define BM_SLPCR_EN_DSM				0x80000000
#define BM_SLPCR_RBC_EN				0x40000000
#define BM_SLPCR_REG_BYPASS_COUNT		0x3f000000
#define BM_SLPCR_VSTBY				0x4
#define BM_SLPCR_SBYOS				0x2
#define BM_SLPCR_BYPASS_PMIC_READY		0x1
#define BM_SLPCR_EN_A7_FASTWUP_WAIT_MODE	0x10000
#define BM_GPC_PGC_ACK_SEL_A7_DUMMY_PUP_ACK	0x80000000
#define BM_GPC_PGC_ACK_SEL_A7_DUMMY_PDN_ACK	0x8000
#define BM_GPC_PGC_CORE_PUPSCR			0x7fff80
#if defined(CONFIG_IMX_THERMAL)
#endif
#if CONFIG_IS_ENABLED(IMX_RDC)
#endif
#if defined(CONFIG_IMX_HAB)
#endif
#ifdef CONFIG_REVISION_TAG
#endif
#ifdef CONFIG_APBH_DMA
#endif
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#if CONFIG_IS_ENABLED(IMX_RDC)
#endif
#else
#endif
#ifdef CONFIG_ARCH_MISC_INIT
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#ifdef CONFIG_FSL_CAAM
#endif
#endif
#ifdef CONFIG_SERIAL_TAG
#endif
#ifndef CONFIG_SPL_BUILD
#if defined(CONFIG_VIDEO_MXS) && !defined(CONFIG_DM_VIDEO)
#endif
#endif
