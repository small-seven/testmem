#include <asm/io.h>
#include <common.h>
#include <dm.h>
#include <dma-uclass.h>
#include <asm/omap_common.h>
#include <asm/ti-common/ti-edma3.h>
#define EDMA3_SL_BASE(slot)			(0x4000 + ((slot) << 5))
#define EDMA3_SL_MAX_NUM			512
#define EDMA3_SLOPT_FIFO_WIDTH_MASK		(0x7 << 8)
#define EDMA3_QCHMAP(ch)			0x0200 + ((ch) << 2)
#define EDMA3_CHMAP_PARSET_MASK			0x1ff
#define EDMA3_CHMAP_PARSET_SHIFT		0x5
#define EDMA3_CHMAP_TRIGWORD_SHIFT		0x2
#define EDMA3_QEMCR				0x314
#define EDMA3_IPR				0x1068
#define EDMA3_IPRH				0x106c
#define EDMA3_ICR				0x1070
#define EDMA3_ICRH				0x1074
#define EDMA3_QEECR				0x1088
#define EDMA3_QEESR				0x108c
#define EDMA3_QSECR				0x1094
#define EDMA_FILL_BUFFER_SIZE			512
#ifndef CONFIG_DMA
#else
#endif /* CONFIG_DMA */
