#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <init.h>
#include <linux/libfdt.h>
#include <linux/sizes.h>
#include <pci.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/armv8/mmu.h>
#define USABLE_RAM_SIZE		0x80000000
#define MV_SIP_DRAM_SIZE	0x82000010
#ifdef CONFIG_DM_PCI
#endif
