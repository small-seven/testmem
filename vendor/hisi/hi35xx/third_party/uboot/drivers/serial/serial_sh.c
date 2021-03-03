#include <common.h>
#include <errno.h>
#include <clk.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <serial.h>
#include <linux/compiler.h>
#include <dm/platform_data/serial_sh.h>
#include "serial_sh.h"
#if defined(CONFIG_CPU_SH7780)
#elif defined(CONFIG_CPU_SH7763)
#else
#endif
#if defined(CONFIG_RZA1)
#endif
#if CONFIG_IS_ENABLED(DM_SERIAL)
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#else /* CONFIG_DM_SERIAL */
#if defined(CONFIG_CONS_SCIF0)
# define SCIF_BASE	SCIF0_BASE
#elif defined(CONFIG_CONS_SCIF1)
# define SCIF_BASE	SCIF1_BASE
#elif defined(CONFIG_CONS_SCIF2)
# define SCIF_BASE	SCIF2_BASE
#elif defined(CONFIG_CONS_SCIF3)
# define SCIF_BASE	SCIF3_BASE
#elif defined(CONFIG_CONS_SCIF4)
# define SCIF_BASE	SCIF4_BASE
#elif defined(CONFIG_CONS_SCIF5)
# define SCIF_BASE	SCIF5_BASE
#elif defined(CONFIG_CONS_SCIF6)
# define SCIF_BASE	SCIF6_BASE
#elif defined(CONFIG_CONS_SCIF7)
# define SCIF_BASE	SCIF7_BASE
#elif defined(CONFIG_CONS_SCIFA0)
# define SCIF_BASE	SCIFA0_BASE
#else
# error "Default SCIF doesn't set....."
#endif
#if defined(CONFIG_SCIF_A)
#elif defined(CONFIG_SCI)
#else
#endif
#ifdef CONFIG_SCIF_USE_EXT_CLK
#endif
#endif /* CONFIG_DM_SERIAL */
