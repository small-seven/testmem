#include <cpu_func.h>
#include <linux/list.h>
#include <common.h>
#include <malloc.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/dma.h>
#include <asm/mach-imx/regs-apbh.h>
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#else
#endif
#if defined(CONFIG_MX23)
#elif (defined(CONFIG_MX28) || defined(CONFIG_MX6) || defined(CONFIG_MX7))
#endif
void mxs_dma_desc_free(struct mxs_dma_desc *pdesc)
{
	if (pdesc == NULL)
		return;

	free(pdesc);
}
#ifdef CONFIG_APBH_DMA_BURST8
#else
#endif
#ifdef CONFIG_APBH_DMA_BURST
#else
#endif
