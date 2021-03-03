#include <common.h>
#include <linux/kbuild.h>
#include <linux/arm-smccc.h>
#if defined(CONFIG_MX25) || defined(CONFIG_MX27) || defined(CONFIG_MX35) \
#include <asm/arch/imx-regs.h>
#endif
#if defined(CONFIG_MX25)
#endif
#if defined(CONFIG_MX27)
#endif
#if defined(CONFIG_MX35)
#endif
#if defined(CONFIG_MX51) || defined(CONFIG_MX53)
#if defined(CONFIG_MX53)
#endif
#endif
#ifdef CONFIG_ARM_SMCCC
#endif
