#include <common.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#if CONFIG_SYS_FSL_SEC_COMPAT == 2 || CONFIG_SYS_FSL_SEC_COMPAT >= 4
#include <fsl_sec.h>
#endif
#if CONFIG_SYS_FSL_SEC_COMPAT == 2 /* SEC 2.x/3.x */
#elif CONFIG_SYS_FSL_SEC_COMPAT >= 4  /* SEC4 */
#endif
