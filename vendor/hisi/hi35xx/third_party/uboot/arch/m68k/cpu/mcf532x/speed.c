#include <common.h>
#include <asm/processor.h>
#include <asm/immap.h>
#include <asm/io.h>
#define MAX_FVCO	500000	/* KHz */
#define MAX_FSYS	80000	/* KHz */
#define MIN_FSYS	58333	/* KHz */
#ifdef CONFIG_MCF5301x
#define FREF		20000	/* KHz */
#define MAX_MFD		63	/* Multiplier */
#define MIN_MFD		0	/* Multiplier */
#define USBDIV		8
#define MIN_LPD		(0)	/* Divider (not encoded) */
#define MAX_LPD		(15)	/* Divider (not encoded) */
#define DEFAULT_LPD	(0)	/* Divider (not encoded) */
#endif
#ifdef CONFIG_MCF532x
#define FREF		16000	/* KHz */
#define MAX_MFD		135	/* Multiplier */
#define MIN_MFD		88	/* Multiplier */
#define MIN_LPD		(1 << 0)	/* Divider (not encoded) */
#define MAX_LPD		(1 << 15)	/* Divider (not encoded) */
#define DEFAULT_LPD	(1 << 1)	/* Divider (not encoded) */
#endif
#define BUSDIV		6	/* Divider */
#ifdef CONFIG_MCF5301x
#endif
#ifdef CONFIG_MCF532x
#endif
#ifdef CONFIG_MCF5301x
#endif
#ifdef CONFIG_MCF532x
#endif
#ifdef CONFIG_MCF532x
#endif
#ifdef CONFIG_MCF5301x
#endif
#ifdef CONFIG_MCF532x
#endif
#ifdef CONFIG_MCF5301x
#endif
#ifdef CONFIG_MCF532x
#endif
#if !defined(CONFIG_MONITOR_IS_IN_RAM)
#ifdef CONFIG_MCF5301x
#endif
#ifdef CONFIG_MCF532x
#endif
#ifdef CONFIG_MCF532x
#endif
#endif /* !defined(CONFIG_MONITOR_IS_IN_RAM) */
#ifdef CONFIG_SYS_I2C_FSL
#endif
