#include <common.h>
#include <asm/processor.h>
#include <asm/immap.h>
#include <asm/io.h>
#if defined(CONFIG_M5208)
#endif
#if defined(CONFIG_M5249) || defined(CONFIG_M5253)
#ifndef CONFIG_SYS_PLL_BYPASS
#ifdef CONFIG_M5249
#ifdef CONFIG_SYS_FAST_CLK
#else
#endif
#endif				/* CONFIG_M5249 */
#ifdef CONFIG_M5253
#endif				/* CONFIG_M5253 */
#endif				/* #ifndef CONFIG_SYS_PLL_BYPASS */
#endif				/* CONFIG_M5249 || CONFIG_M5253 */
#if defined(CONFIG_M5275)
#endif
#if defined(CONFIG_M5208) || defined(CONFIG_M5249) || defined(CONFIG_M5253) || \
#else
#endif
#ifdef CONFIG_SYS_I2C_FSL
#ifdef CONFIG_SYS_I2C2_FSL_OFFSET
#endif
#endif
