#include <common.h>
#include <command.h>
#include <dm.h>
#include <serial.h>
#include <watchdog.h>
#include <asm/cpm_8xx.h>
#include <linux/compiler.h>
#if defined(CONFIG_8xx_CONS_SMC1)	/* Console on SMC1 */
#define	SMC_INDEX	0
#define PROFF_SMC	PROFF_SMC1
#define CPM_CR_CH_SMC	CPM_CR_CH_SMC1
#define IOPINS		0xc0
#elif defined(CONFIG_8xx_CONS_SMC2)	/* Console on SMC2 */
#define SMC_INDEX	1
#define PROFF_SMC	PROFF_SMC2
#define CPM_CR_CH_SMC	CPM_CR_CH_SMC2
#define IOPINS		0xc00
#endif /* CONFIG_8xx_CONS_SMCx */
