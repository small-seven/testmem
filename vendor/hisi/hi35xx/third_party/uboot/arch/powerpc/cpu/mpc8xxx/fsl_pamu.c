#include <common.h>
#include <linux/log2.h>
#include <malloc.h>
#include <asm/fsl_pamu.h>
#if (defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_PPAACT_ADDR))
#else
#endif
#if (defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_SPAACT_ADDR))
#else
#endif
