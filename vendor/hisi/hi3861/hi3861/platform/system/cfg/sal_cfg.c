#include "sal_cfg.h"
#include <hi_early_debug.h>
#include <hi_nv.h>
#include <hi_sal.h>
#include <hi_sal_cfg.h>
#include <hi_watchdog.h>
#ifdef CONFIG_TEE_HUKS_SUPPORT
#if defined(CONFIG_FACTORY_TEST_MODE) && defined(CONFIG_HILINK) && defined(CONFIG_HILINK_PKI_SUPPORT)
#else
#endif
#else
#endif
#ifdef CONFIG_DIAG_SUPPORT
#endif
