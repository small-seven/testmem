#include <common.h>
#include <asm/processor.h>
#include <asm/mmu.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/io.h>
#include <env.h>
#include <miiphy.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <fsl_mdio.h>
#include <tsec.h>
#include <jffs2/load_kernel.h>
#include <mtd_node.h>
#include <flash.h>
#include <netdev.h>
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_FDT_FIXUP_PARTITIONS
#endif
#ifdef CONFIG_FDT_FIXUP_PARTITIONS
#endif
#endif
