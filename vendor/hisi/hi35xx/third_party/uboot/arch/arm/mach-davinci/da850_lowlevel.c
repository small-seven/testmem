#include <common.h>
#include <nand.h>
#include <ns16550.h>
#include <post.h>
#include <asm/arch/da850_lowlevel.h>
#include <asm/arch/hardware.h>
#include <asm/arch/davinci_misc.h>
#include <asm/arch/ddr2_defs.h>
#include <asm/ti-common/davinci_nand.h>
#include <asm/arch/pll_defs.h>
#if defined(CONFIG_SYS_DA850_PLL_INIT)
#if defined(CONFIG_SYS_DA850_PLL0_PREDIV)
#endif
#endif /* CONFIG_SYS_DA850_PLL_INIT */
#if defined(CONFIG_SYS_DA850_DDR_INIT)
#endif /* CONFIG_SYS_DA850_DDR_INIT */
#if defined(CONFIG_SYS_DA850_PLL_INIT)
#endif
#if defined(CONFIG_SYS_DA850_CS2CFG)
#endif
#if defined(CONFIG_SYS_DA850_CS3CFG)
#endif
#if !CONFIG_IS_ENABLED(DM_SERIAL)
#endif
#if (CONFIG_SYS_NS16550_COM1 == DAVINCI_UART0_BASE)
#else
#endif
#if defined(CONFIG_SYS_DA850_DDR_INIT)
#endif
