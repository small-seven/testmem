#include <common.h>
#include <asm/io.h>
#if defined(CONFIG_MX53)
#define MEMCTL_BASE	ESDCTL_BASE_ADDR
#elif defined(CONFIG_MX6)
#define MEMCTL_BASE	MMDC_P0_BASE_ADDR
#elif defined(CONFIG_MX7ULP)
#define MEMCTL_BASE	MMDC0_RBASE
#endif
#define ESD_MMDC_CTL_GET_ROW(mdctl)	((ctl >> 24) & 7)
#define ESD_MMDC_CTL_GET_COLUMN(mdctl)	((ctl >> 20) & 7)
#define ESD_MMDC_CTL_GET_WIDTH(mdctl)	((ctl >> 16) & 3)
#define ESD_MMDC_CTL_GET_CS1(mdctl)	((ctl >> 30) & 1)
#define ESD_MMDC_MISC_GET_BANK(mdmisc)	((misc >> 5) & 1)
