#include <common.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/mc_cgm_regs.h>
#include <asm/arch/mc_me_regs.h>
#include <asm/arch/mc_rgm_regs.h>
#include <netdev.h>
#include <div64.h>
#include <errno.h>
#if defined(CONFIG_DISPLAY_CPUINFO)
#define SRC_SCR_SW_RST					(1<<12)
#endif
#if defined(CONFIG_FEC_MXC)
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
