#include <common.h>
#include <serial.h>
#include <spl.h>
#include <asm/io.h>
#include <linux/sizes.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/iomux.h>
#include <asm/arch/mx6-ddr.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#define IMX6SDL_DRIVE_STRENGTH		0x28
#define UART_PAD_CTRL	(PAD_CTL_PUS_100K_UP | PAD_CTL_SPEED_MED | \
#ifdef CONFIG_SPL_OS_BOOT
#endif
