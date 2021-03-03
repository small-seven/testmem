#include <common.h>
#include <cpu_func.h>
#include <watchdog.h>
#include <asm/immap.h>
#include <asm/io.h>
#if defined(CONFIG_M5307)
#define MCF5307_SP_ERR_FIX(cs_base, mask)				\
#if (defined(CONFIG_SYS_CS0_BASE) && defined(CONFIG_SYS_CS0_MASK) && \
#else
#warning "Chip Select 0 are not initialized/used"
#endif
#if (defined(CONFIG_SYS_CS1_BASE) && defined(CONFIG_SYS_CS1_MASK) && \
#endif
#if (defined(CONFIG_SYS_CS2_BASE) && defined(CONFIG_SYS_CS2_MASK) && \
#endif
#if (defined(CONFIG_SYS_CS3_BASE) && defined(CONFIG_SYS_CS3_MASK) && \
#endif
#if (defined(CONFIG_SYS_CS4_BASE) && defined(CONFIG_SYS_CS4_MASK) && \
#endif
#if (defined(CONFIG_SYS_CS5_BASE) && defined(CONFIG_SYS_CS5_MASK) && \
#endif
#if (defined(CONFIG_SYS_CS6_BASE) && defined(CONFIG_SYS_CS6_MASK) && \
#endif
#if (defined(CONFIG_SYS_CS7_BASE) && defined(CONFIG_SYS_CS7_MASK) && \
#endif
#endif
