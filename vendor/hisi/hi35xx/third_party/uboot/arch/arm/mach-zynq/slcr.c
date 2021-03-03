#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#define SLCR_LOCK_MAGIC		0x767B
#define SLCR_UNLOCK_MAGIC	0xDF0D
#define SLCR_NAND_L2_SEL		0x10
#define SLCR_NAND_L2_SEL_MASK		0x1F
#define SLCR_USB_L1_SEL			0x04
#define SLCR_IDCODE_MASK	0x1F000
#define SLCR_IDCODE_SHIFT	12
