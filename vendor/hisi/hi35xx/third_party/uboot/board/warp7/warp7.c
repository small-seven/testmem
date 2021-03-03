#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/mx7-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/hab.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/io.h>
#include <common.h>
#include <env.h>
#include <asm/arch/crm_regs.h>
#include <netdev.h>
#include <power/pmic.h>
#include <power/pfuze3000_pmic.h>
#include "../freescale/common/pfuze.h"
#include <asm/setup.h>
#include <asm/bootm.h>
#define UART_PAD_CTRL  (PAD_CTL_DSE_3P3V_49OHM | PAD_CTL_PUS_PU100KOHM | \
#ifdef CONFIG_OPTEE_TZDRAM_SIZE
#endif
#ifdef CONFIG_DM_PMIC
#endif
#ifdef CONFIG_USB_ETHER
#endif
#ifdef CONFIG_OPTEE_TZDRAM_SIZE
#else
#endif
#ifdef CONFIG_SERIAL_TAG
#endif
#ifdef CONFIG_IMX_HAB
#else
#endif
#ifdef CONFIG_SERIAL_TAG
#endif
