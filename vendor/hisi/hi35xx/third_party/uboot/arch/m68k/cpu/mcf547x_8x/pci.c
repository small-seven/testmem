#include <common.h>
#include <pci.h>
#include <asm/io.h>
#include <asm/immap.h>
#if defined(CONFIG_PCI)
#define CONFIG_SYS_PCI_SYS_MEM_BUS	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_PCI_SYS_MEM_PHYS	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_PCI_SYS_MEM_SIZE	(1024 * 1024 * 1024)
#define cfg_read(val, addr, type, op)		*val = op((type)(addr));
#define cfg_write(val, addr, type, op)		op((type *)(addr), (val));
#define PCI_OP(rw, size, type, op, mask)				\
#ifdef CONFIG_SYS_PCI_BAR0
#endif
#ifdef CONFIG_SYS_PCI_BAR1
#endif
#endif				/* CONFIG_PCI */
