#include <common.h>
#include <dm.h>
#include <init.h>
#include <malloc.h>
#include <errno.h>
#include <linux/compiler.h>
#include <cavium/atf.h>
#include <asm/armv8/mmu.h>
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#include <dm/platform_data/serial_pl01x.h>
#endif
#ifdef CONFIG_PCI
#endif
