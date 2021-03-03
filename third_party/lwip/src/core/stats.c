#include "lwip/opt.h"
#if LWIP_STATS /* don't build if not configured for use in lwipopts.h */
#include "lwip/def.h"
#include "lwip/stats.h"
#include "lwip/mem.h"
#include "lwip/debug.h"
#include <string.h>
#ifdef LWIP_DEBUG
#if MEM_STATS
#endif /* MEM_STATS */
#endif /* LWIP_DEBUG */
#if LWIP_STATS_DISPLAY
#if IGMP_STATS || MLD6_STATS
#endif /* IGMP_STATS || MLD6_STATS */
#if MEM_STATS || MEMP_STATS
stats_display_mem(struct stats_mem *mem, const char *name)
{
  LWIP_PLATFORM_DIAG(("\nMEM %s\n\t", name));
  LWIP_PLATFORM_DIAG(("avail: %"MEM_SIZE_F"\n\t", mem->avail));
  LWIP_PLATFORM_DIAG(("used: %"MEM_SIZE_F"\n\t", mem->used));
  LWIP_PLATFORM_DIAG(("max: %"MEM_SIZE_F"\n\t", mem->max));
  LWIP_PLATFORM_DIAG(("err: %"STAT_COUNTER_F"\n", mem->err));
}
#if MEMP_STATS
stats_display_memp(struct stats_mem *mem, int idx)
{
  if (idx < MEMP_MAX) {
    stats_display_mem(mem, mem->name);
  }
}
#endif /* MEMP_STATS */
#endif /* MEM_STATS || MEMP_STATS */
#if SYS_STATS
#endif /* SYS_STATS */
#endif /* LWIP_STATS_DISPLAY */
#endif /* LWIP_STATS */
