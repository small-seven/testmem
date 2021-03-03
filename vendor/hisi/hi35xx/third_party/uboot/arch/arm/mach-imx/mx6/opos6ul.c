#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/io.h>
#include <common.h>
#include <env.h>
#ifdef CONFIG_FEC_MXC
#include <miiphy.h>
#endif /* CONFIG_FEC_MXC */
#ifdef CONFIG_FEC_MXC
#endif
#ifdef CONFIG_SPL_BUILD
#include <asm/arch/mx6-ddr.h>
#include <linux/libfdt.h>
#include <spl.h>
#endif /* CONFIG_SPL_BUILD */
