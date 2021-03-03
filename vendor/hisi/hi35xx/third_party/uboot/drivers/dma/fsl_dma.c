#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <asm/fsl_dma.h>
#define FSL_DMA_MAX_SIZE	(0x3ffffff)
#if defined(CONFIG_MPC83xx)
#define FSL_DMA_MR_DEFAULT (FSL_DMA_MR_CTM_DIRECT | FSL_DMA_MR_DMSEN)
#else
#define FSL_DMA_MR_DEFAULT (FSL_DMA_MR_BWC_DIS | FSL_DMA_MR_CTM_DIRECT)
#endif
#if defined(CONFIG_MPC83xx)
#elif defined(CONFIG_MPC85xx)
#elif defined(CONFIG_MPC86xx)
#else
#error "Freescale DMA engine not supported on your processor"
#endif
#if defined(CONFIG_MPC85xx)
#elif defined(CONFIG_MPC86xx)
#endif
#if defined(CONFIG_MPC83xx)
#else
#endif
#if defined(CONFIG_MPC83xx)
#else
#endif
#if !defined(CONFIG_MPC83xx)
#endif
#if !defined(CONFIG_MPC83xx)
#endif
#if ((!defined CONFIG_MPC83xx && defined(CONFIG_DDR_ECC) &&	\
#endif
