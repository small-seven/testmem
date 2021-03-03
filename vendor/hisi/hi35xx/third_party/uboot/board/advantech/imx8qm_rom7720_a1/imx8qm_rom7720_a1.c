#include <common.h>
#include <errno.h>
#include <linux/libfdt.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/clock.h>
#include <asm/arch/sci/sci.h>
#include <asm/arch/imx8-pins.h>
#include <asm/arch/iomux.h>
#include <asm/arch/sys_proto.h>
#define UART_PAD_CTRL	((SC_PAD_CONFIG_OUT_IN << PADRING_CONFIG_SHIFT) | \
#if IS_ENABLED(CONFIG_FEC_MXC)
#include <miiphy.h>
#ifdef CONFIG_FEC_ENABLE_MAX7322
#endif
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#ifdef CONFIG_AHAB_BOOT
#endif
