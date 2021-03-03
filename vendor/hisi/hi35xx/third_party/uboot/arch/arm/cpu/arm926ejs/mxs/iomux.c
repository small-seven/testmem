#include <common.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#if	defined(CONFIG_MX23)
#define	DRIVE_OFFSET	0x200
#define	PULL_OFFSET	0x400
#elif	defined(CONFIG_MX28)
#define	DRIVE_OFFSET	0x300
#define	PULL_OFFSET	0x600
#else
#error "Please select CONFIG_MX23 or CONFIG_MX28"
#endif
