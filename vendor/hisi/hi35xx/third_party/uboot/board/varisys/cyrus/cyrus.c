#include <common.h>
#include <command.h>
#include <env.h>
#include <init.h>
#include <netdev.h>
#include <linux/compiler.h>
#include <asm/mmu.h>
#include <asm/processor.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_law.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_portals.h>
#include <asm/fsl_liodn.h>
#include <fm_eth.h>
#include <pci.h>
#include "cyrus.h"
#include "../common/eeprom.h"
#define GPIO_OPENDRAIN 0x30000000
#define GPIO_DIR       0x3c000004
#define GPIO_INITIAL   0x30000000
#define GPIO_VGA_SWITCH 0x00001000
#ifdef CONFIG_SYS_DPAA_QBMAN
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
