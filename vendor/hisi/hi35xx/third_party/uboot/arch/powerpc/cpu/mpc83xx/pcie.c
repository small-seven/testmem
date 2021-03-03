#include <common.h>
#include <pci.h>
#include <mpc83xx.h>
#include <asm/io.h>
#define PCIE_MAX_BUSES 2
#if defined(CONFIG_SYS_PCIE2_CFG_BASE) && defined(CONFIG_SYS_PCIE2_CFG_SIZE)
#endif
#ifdef CONFIG_83XX_GENERIC_PCIE_REGISTER_HOSES
#define cfg_read(val, addr, type, op) \
#define cfg_write(val, addr, type, op) \
#define cfg_read_err(val) do { *val = -1; } while (0)
#define cfg_write_err(val) do { } while (0)
#define PCIE_OP(rw, size, type, op)					\
#ifdef CONFIG_PCI_SCAN_SHOW
#endif
#else
#endif /* CONFIG_83XX_GENERIC_PCIE_REGISTER_HOSES */
#define PCI_LTSSM	0x404 /* PCIe Link Training, Status State Machine */
#define PCI_LTSSM_L0	0x16 /* L0 state */
