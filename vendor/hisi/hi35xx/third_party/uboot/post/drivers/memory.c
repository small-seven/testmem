#include <common.h>
#include <post.h>
#include <watchdog.h>
#if CONFIG_POST & (CONFIG_SYS_POST_MEMORY | CONFIG_SYS_POST_MEM_REGIONS)
#undef  INJECT_DATA_ERRORS
#undef  INJECT_ADDRESS_ERRORS
#ifdef INJECT_DATA_ERRORS
#warning "Injecting data line errors for testing purposes"
#endif
#ifdef INJECT_ADDRESS_ERRORS
#warning "Injecting address line errors for testing purposes"
#endif
#ifdef INJECT_DATA_ERRORS
#endif
#ifdef INJECT_ADDRESS_ERRORS
#endif
#endif /* CONFIG_POST&(CONFIG_SYS_POST_MEMORY|CONFIG_SYS_POST_MEM_REGIONS) */
