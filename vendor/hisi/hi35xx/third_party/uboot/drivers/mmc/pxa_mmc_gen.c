#include <common.h>
#include <asm/arch/hardware.h>
#include <asm/arch/regs-mmc.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <malloc.h>
#include <mmc.h>
#if defined(CONFIG_CPU_PXA25X)
#define PXAMMC_FIFO_SIZE	1
#define PXAMMC_MIN_SPEED	312500
#define PXAMMC_MAX_SPEED	20000000
#define PXAMMC_HOST_CAPS	(0)
#elif defined(CONFIG_CPU_PXA27X)
#define PXAMMC_CRC_SKIP
#define PXAMMC_FIFO_SIZE	32
#define PXAMMC_MIN_SPEED	304000
#define PXAMMC_MAX_SPEED	19500000
#define PXAMMC_HOST_CAPS	(MMC_MODE_4BIT)
#elif defined(CONFIG_CPU_MONAHANS)
#define PXAMMC_FIFO_SIZE	32
#define PXAMMC_MIN_SPEED	304000
#define PXAMMC_MAX_SPEED	26000000
#define PXAMMC_HOST_CAPS	(MMC_MODE_4BIT | MMC_MODE_HS)
#else
#error "This CPU isn't supported by PXA MMC!"
#endif
#define MMC_STAT_ERRORS							\
#define PXA_MMC_TIMEOUT	100
#ifdef	PXAMMC_CRC_SKIP
#endif
#ifndef	CONFIG_CPU_MONAHANS	/* PXA2xx */
#else				/* PXA3xx */
#endif
