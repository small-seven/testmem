#include <common.h>
#include <div64.h>
#include <asm/io.h>
#include <errno.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#ifdef CONFIG_FSL_ESDHC_IMX
#if CONFIG_SYS_FSL_ESDHC_ADDR == USDHC0_RBASE
#elif CONFIG_SYS_FSL_ESDHC_ADDR == USDHC1_RBASE
#endif
#endif
#ifdef CONFIG_SYS_I2C_IMX_LPI2C
#endif
#ifdef CONFIG_MXC_OCOTP
#define OCOTP_CTRL_PCC1_SLOT		(38)
#define OCOTP_CTRL_HIGH4K_PCC1_SLOT	(39)
#endif
#ifdef CONFIG_USB_MAX_CONTROLLER_COUNT
#endif
#ifndef CONFIG_CLK_DEBUG
#endif
#ifdef CONFIG_IMX_HAB
#endif
#ifndef CONFIG_SPL_BUILD
#endif
