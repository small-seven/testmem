#include <common.h>
#include <miiphy.h>
#include <linux/errno.h>
#include <mv88e6352.h>
#define SMI_HDR		((0x8 | 0x1) << 12)
#define SMI_BUSY_MASK	(0x8000)
#define SMIRD_OP	(0x2 << 10)
#define SMIWR_OP	(0x1 << 10)
#define SMI_MASK	0x1f
#define PORT_SHIFT	5
#define COMMAND_REG	0
#define DATA_REG	1
#define GLOBAL		0x1b
#define GLOBAL_STATUS	0x00
#define PPU_STATE	0x8000
#define GLOBAL_CTRL	0x04
#define SW_RESET	0x8000
#define PPU_ENABLE	0x4000
