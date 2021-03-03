#include <common.h>
#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx8-pins.h>
#include <asm/arch/iomux.h>
#include <asm/arch/sci/sci.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <env.h>
#include <errno.h>
#include <linux/libfdt.h>
#include "../common/tdx-cfg-block.h"
#define UART_PAD_CTRL	((SC_PAD_CONFIG_OUT_IN << PADRING_CONFIG_SHIFT) | \
#if IS_ENABLED(CONFIG_DM_GPIO)
#else
#endif
#if IS_ENABLED(CONFIG_FEC_MXC)
#include <miiphy.h>
#endif
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
