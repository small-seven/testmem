#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <env.h>
#include <init.h>
#include <pci.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/fsl_pci.h>
#include <asm/io.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <netdev.h>
#include <fdtdec.h>
#include <errno.h>
#include <malloc.h>
#if defined(CONFIG_OF_BOARD_SETUP)
#endif
