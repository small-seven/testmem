#include <common.h>
#include <dm/ofnode.h>
#include <dm/util.h>
#include <linux/libfdt.h>
#include <vsprintf.h>
#ifdef CONFIG_DM_WARN
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#if defined(CONFIG_SPL_BUILD) || defined(CONFIG_TPL_BUILD)
#else
#endif
#endif
