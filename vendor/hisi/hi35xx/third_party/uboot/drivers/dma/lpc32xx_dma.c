#include <common.h>
#include <errno.h>
#include <asm/arch/dma.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clk.h>
#include <asm/arch/sys_proto.h>
#include <asm/io.h>
#define DMA_NO_OF_CHANNELS	8
#define DMAC_CTRL_ENABLE	(1 << 0) /* For enabling the DMA controller */
