#include <common.h>
#include <init.h>
#include <jffs2/jffs2.h>
#include <nand.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <linux/errno.h>
#include <u-boot/crc.h>
#include "apf27.h"
#include "fpga.h"
#define APF27_PORT_INIT(n) apf27_port_init(PORT##n, ACFG_DR_##n##_VAL,	  \
#ifdef CONFIG_MXC_UART
#endif
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_MMC_MXC
#endif
#if defined(CONFIG_FPGA)
#endif
#ifdef CONFIG_SPL_BUILD
#endif /* CONFIG_SPL_BUILD */
