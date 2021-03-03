#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#ifdef CONFIG_SYS_NONCACHED_MEMORY
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#endif
#endif /* CONFIG_SYS_NONCACHED_MEMORY */
#if CONFIG_IS_ENABLED(SYS_THUMB_BUILD)
#endif
