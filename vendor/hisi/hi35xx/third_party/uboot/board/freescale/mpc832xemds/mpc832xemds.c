#include <common.h>
#include <init.h>
#include <ioports.h>
#include <mpc83xx.h>
#include <i2c.h>
#include <miiphy.h>
#include <command.h>
#if defined(CONFIG_PCI)
#include <pci.h>
#endif
#include <asm/mmu.h>
#if defined(CONFIG_OF_LIBFDT)
#include <linux/libfdt.h>
#endif
#if defined(CONFIG_PQ_MDS_PIB)
#include "../common/pq-mds-pib.h"
#endif
#ifdef CONFIG_PQ_MDS_PIB
#endif
#if (CONFIG_SYS_DDR_SIZE != 128)
#warning Currenly any ddr size other than 128 is not supported
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif
