#include <common.h>
#include <asm/cpm_85xx.h>
#include <serial.h>
#include <linux/compiler.h>
#if defined(CONFIG_CONS_ON_SCC)
#if CONFIG_CONS_INDEX == 1	/* Console on SCC1 */
#define SCC_INDEX		0
#define PROFF_SCC		PROFF_SCC1
#define CMXSCR_MASK		(CMXSCR_GR1|CMXSCR_SC1|\
#define CMXSCR_VALUE		(CMXSCR_RS1CS_BRG1|CMXSCR_TS1CS_BRG1)
#define CPM_CR_SCC_PAGE		CPM_CR_SCC1_PAGE
#define CPM_CR_SCC_SBLOCK	CPM_CR_SCC1_SBLOCK
#elif CONFIG_CONS_INDEX == 2	/* Console on SCC2 */
#define SCC_INDEX		1
#define PROFF_SCC		PROFF_SCC2
#define CMXSCR_MASK		(CMXSCR_GR2|CMXSCR_SC2|\
#define CMXSCR_VALUE		(CMXSCR_RS2CS_BRG2|CMXSCR_TS2CS_BRG2)
#define CPM_CR_SCC_PAGE		CPM_CR_SCC2_PAGE
#define CPM_CR_SCC_SBLOCK	CPM_CR_SCC2_SBLOCK
#elif CONFIG_CONS_INDEX == 3	/* Console on SCC3 */
#define SCC_INDEX		2
#define PROFF_SCC		PROFF_SCC3
#define CMXSCR_MASK		(CMXSCR_GR3|CMXSCR_SC3|\
#define CMXSCR_VALUE		(CMXSCR_RS3CS_BRG3|CMXSCR_TS3CS_BRG3)
#define CPM_CR_SCC_PAGE		CPM_CR_SCC3_PAGE
#define CPM_CR_SCC_SBLOCK	CPM_CR_SCC3_SBLOCK
#elif CONFIG_CONS_INDEX == 4	/* Console on SCC4 */
#define SCC_INDEX		3
#define PROFF_SCC		PROFF_SCC4
#define CMXSCR_MASK		(CMXSCR_GR4|CMXSCR_SC4|\
#define CMXSCR_VALUE		(CMXSCR_RS4CS_BRG4|CMXSCR_TS4CS_BRG4)
#define CPM_CR_SCC_PAGE		CPM_CR_SCC4_PAGE
#define CPM_CR_SCC_SBLOCK	CPM_CR_SCC4_SBLOCK
#else
#error "console not correctly defined"
#endif
#if defined(CONFIG_CONS_USE_EXTC)
#else
#endif
#endif	/* CONFIG_CONS_ON_SCC */
