#include <common.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/mach-imx/dma.h>
#include <asm/arch/gpio.h>
#include <asm/arch/iomux.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <linux/compiler.h>
#ifdef	CONFIG_ARCH_MISC_INIT
#endif
#ifdef	CONFIG_APBH_DMA
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif
#if defined(CONFIG_MX28) && defined(CONFIG_CMD_NET)
#endif
#ifdef	CONFIG_MX28_FEC_MAC_IN_OCOTP
#define	MXS_OCOTP_MAX_TIMEOUT	1000000
#else
#endif
