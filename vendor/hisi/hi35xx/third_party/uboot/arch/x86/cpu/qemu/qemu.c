#include <common.h>
#include <cpu_func.h>
#include <pci.h>
#include <qfw.h>
#include <asm/irq.h>
#include <asm/post.h>
#include <asm/processor.h>
#include <asm/arch/device.h>
#include <asm/arch/qemu.h>
#ifdef CONFIG_QFW
#define FW_CONTROL_PORT	0x510
#define FW_DATA_PORT		0x511
#define FW_DMA_PORT_LOW	0x514
#define FW_DMA_PORT_HIGH	0x518
#endif
#ifdef CONFIG_QFW
#endif
#if !CONFIG_IS_ENABLED(SPL_X86_32BIT_INIT)
#endif
#ifdef CONFIG_GENERATE_MP_TABLE
#endif
