#include <cpu_func.h>
#include <asm/io.h>
#include <asm/psci.h>
#include <asm/secure.h>
#include <asm/arch/imx-regs.h>
#include <asm/armv7.h>
#include <asm/gic.h>
#include <linux/bitops.h>
#include <common.h>
#include <fsl_wdog.h>
#define GPC_LPCR_A7_BSC	0x0
#define GPC_LPCR_A7_AD		0x4
#define GPC_SLPCR		0x14
#define GPC_PGC_ACK_SEL_A7	0x24
#define GPC_IMR1_CORE0		0x30
#define GPC_SLOT0_CFG		0xb0
#define GPC_CPU_PGC_SW_PUP_REQ	0xf0
#define GPC_CPU_PGC_SW_PDN_REQ	0xfc
#define GPC_PGC_C0		0x800
#define GPC_PGC_C0		0x800
#define GPC_PGC_C1		0x840
#define GPC_PGC_SCU		0x880
#define BM_LPCR_A7_BSC_CPU_CLK_ON_LPM		0x4000
#define BM_LPCR_A7_BSC_LPM1			0xc
#define BM_LPCR_A7_BSC_LPM0			0x3
#define BP_LPCR_A7_BSC_LPM0			0
#define BM_SLPCR_EN_DSM				0x80000000
#define BM_SLPCR_RBC_EN				0x40000000
#define BM_SLPCR_REG_BYPASS_COUNT		0x3f000000
#define BM_SLPCR_VSTBY				0x4
#define BM_SLPCR_SBYOS				0x2
#define BM_SLPCR_BYPASS_PMIC_READY		0x1
#define BM_LPCR_A7_AD_L2PGE			0x10000
#define BM_LPCR_A7_AD_EN_C1_PUP			0x800
#define BM_LPCR_A7_AD_EN_C0_PUP			0x200
#define BM_LPCR_A7_AD_EN_PLAT_PDN		0x10
#define BM_LPCR_A7_AD_EN_C1_PDN			0x8
#define BM_LPCR_A7_AD_EN_C0_PDN			0x2
#define BM_CPU_PGC_SW_PDN_PUP_REQ_CORE0_A7	0x1
#define BM_CPU_PGC_SW_PDN_PUP_REQ_CORE1_A7	0x2
#define BM_GPC_PGC_ACK_SEL_A7_PD_DUMMY_ACK	0x8000
#define BM_GPC_PGC_ACK_SEL_A7_PU_DUMMY_ACK	0x80000000
#define MAX_SLOT_NUMBER				10
#define A7_LPM_WAIT				0x5
#define A7_LPM_STOP				0xa
#define BM_SYS_COUNTER_CNTCR_FCR1 0x200
#define BM_SYS_COUNTER_CNTCR_FCR0 0x100
#define REG_SET		0x4
#define REG_CLR		0x8
#define ANADIG_ARM_PLL		0x60
#define ANADIG_DDR_PLL		0x70
#define ANADIG_SYS_PLL		0xb0
#define ANADIG_ENET_PLL		0xe0
#define ANADIG_AUDIO_PLL	0xf0
#define ANADIG_VIDEO_PLL	0x130
#define BM_ANATOP_ARM_PLL_OVERRIDE	BIT(20)
#define BM_ANATOP_DDR_PLL_OVERRIDE	BIT(19)
#define BM_ANATOP_SYS_PLL_OVERRIDE	(0x1ff << 17)
#define BM_ANATOP_ENET_PLL_OVERRIDE	BIT(13)
#define BM_ANATOP_AUDIO_PLL_OVERRIDE	BIT(24)
#define BM_ANATOP_VIDEO_PLL_OVERRIDE	BIT(24)
#define DDRC_STAT	0x4
#define DDRC_PWRCTL	0x30
#define DDRC_PSTAT	0x3fc
#define SRC_GPR1_MX7D		0x074
#define SRC_GPR2_MX7D		0x078
#define SRC_A7RCR0		0x004
#define SRC_A7RCR1		0x008
#define BP_SRC_A7RCR0_A7_CORE_RESET0	0
#define BP_SRC_A7RCR1_A7_CORE1_ENABLE	1
#define SNVS_LPCR		0x38
#define BP_SNVS_LPCR_DP_EN	0x20
#define BP_SNVS_LPCR_TOP	0x40
#define CCM_CCGR_SNVS		0x4250
#define CCM_ROOT_WDOG		0xbb80
#define CCM_CCGR_WDOG1		0x49c0
#define MPIDR_AFF0		GENMASK(7, 0)
#define IMX7D_PSCI_NR_CPUS	2
#if IMX7D_PSCI_NR_CPUS > CONFIG_ARMV7_PSCI_NR_CPUS
#error "invalid value for CONFIG_ARMV7_PSCI_NR_CPUS"
#endif
#define imx_cpu_gpr_entry_offset(cpu) \
#define imx_cpu_gpr_para_offset(cpu) \
#define IMX_CPU_SYNC_OFF	~0
#define IMX_CPU_SYNC_ON		0
