#ifdef BCM_GMAC_DEBUG
#ifndef DEBUG
#define DEBUG
#endif
#endif
#include <config.h>
#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#include <net.h>
#include <asm/io.h>
#include <phy.h>
#include "bcm-sf2-eth.h"
#include "bcm-sf2-eth-gmac.h"
#define SPINWAIT(exp, us) { \
#define RX_BUF_SIZE_ALIGNED	ALIGN(RX_BUF_SIZE, ARCH_DMA_MINALIGN)
#define TX_BUF_SIZE_ALIGNED	ALIGN(TX_BUF_SIZE, ARCH_DMA_MINALIGN)
#define DESCP_SIZE_ALIGNED	ALIGN(sizeof(dma64dd_t), ARCH_DMA_MINALIGN)
typedef struct {
	/* misc control bits */
	uint32_t	ctrl1;
	/* buffer count and address extension */
	uint32_t	ctrl2;
	/* memory address of the date buffer, bits 31:0 */
	uint32_t	addrlow;
	/* memory address of the date buffer, bits 63:32 */
	uint32_t	addrhigh;
} dma64dd_t;
#ifdef BCM_GMAC_DEBUG
#endif
