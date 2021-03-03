#include <common.h>
#include <irq_func.h>
#include <watchdog.h>
#include <asm/processor.h>
#include <asm/immap.h>
#include <asm/io.h>
#ifdef	CONFIG_M5272
#if defined(CONFIG_MCFTMR)
#endif				/* CONFIG_MCFTMR */
#endif				/* CONFIG_M5272 */
#if defined(CONFIG_M5208) || defined(CONFIG_M5282) || \
#if defined(CONFIG_M5208)
#else
#endif
#if defined(CONFIG_MCFTMR)
#endif				/* CONFIG_MCFTMR */
#endif				/* CONFIG_M5282 | CONFIG_M5271 | CONFIG_M5275 */
#if defined(CONFIG_M5249) || defined(CONFIG_M5253)
#if defined(CONFIG_MCFTMR)
#endif				/* CONFIG_MCFTMR */
#endif				/* CONFIG_M5249 || CONFIG_M5253 */
