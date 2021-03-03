#include <common.h>
#include <asm/arch/sys_proto.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/mach-imx/regs-common.h>
#define	RESET_MAX_TIMEOUT	1000000
#define	MXS_BLOCK_SFTRST	(1 << 31)
#define	MXS_BLOCK_CLKGATE	(1 << 30)
