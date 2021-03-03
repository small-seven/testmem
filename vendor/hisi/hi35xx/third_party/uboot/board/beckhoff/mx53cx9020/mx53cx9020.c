#include <common.h>
#include <cpu_func.h>
#include <init.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux-mx53.h>
#include <asm/mach-imx/mx5_video.h>
#include <ACEX1K.h>
#include <asm/gpio.h>
#define CCAT_BASE_ADDR ((void *)0xf0000000)
#define CCAT_END_ADDR (CCAT_BASE_ADDR + (1024 * 1024 * 32))
#define CCAT_SIZE 1191788
#define CCAT_SIGN_ADDR (CCAT_BASE_ADDR + 12)
#ifdef CONFIG_USB_EHCI_MX5
#endif
