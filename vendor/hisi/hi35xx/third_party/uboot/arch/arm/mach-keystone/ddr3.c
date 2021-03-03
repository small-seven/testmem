#include <asm/io.h>
#include <common.h>
#include <asm/arch/msmc.h>
#include <asm/arch/ddr3.h>
#include <asm/arch/psc_defs.h>
#include <asm/ti-common/ti-edma3.h>
#define DDR3_EDMA_BLK_SIZE_SHIFT	10
#define DDR3_EDMA_BLK_SIZE		(1 << DDR3_EDMA_BLK_SIZE_SHIFT)
#define DDR3_EDMA_BCNT			0x8000
#define DDR3_EDMA_CCNT			1
#define DDR3_EDMA_XF_SIZE		(DDR3_EDMA_BLK_SIZE * DDR3_EDMA_BCNT)
#define DDR3_EDMA_SLOT_NUM		1
#if defined(CONFIG_SOC_K2HK) || defined(CONFIG_SOC_K2L)
#endif
#if defined(CONFIG_SOC_K2HK) || defined(CONFIG_SOC_K2L)
#endif
#ifdef CONFIG_SOC_K2HK
#endif
