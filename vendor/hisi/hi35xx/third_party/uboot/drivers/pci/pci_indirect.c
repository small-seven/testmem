#include <common.h>
#if !defined(__I386__) && !defined(CONFIG_DM_PCI)
#include <asm/processor.h>
#include <asm/io.h>
#include <pci.h>
#define cfg_read(val, addr, type, op)	*val = op((type)(addr))
#define cfg_write(val, addr, type, op)	op((type *)(addr), (val))
#if defined(CONFIG_E500) || defined(CONFIG_MPC86xx)
#define INDIRECT_PCI_OP(rw, size, type, op, mask)                        \
#else
#define INDIRECT_PCI_OP(rw, size, type, op, mask)			 \
#endif
#endif	/* !__I386__ */
