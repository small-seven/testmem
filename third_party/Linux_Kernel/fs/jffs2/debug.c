#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/pagemap.h>
#include <linux/slab.h>
#include <mtd_dev.h>
#include "los_crc32.h"
#include "nodelist.h"
#include "debug.h"
#ifdef JFFS2_DBG_SANITY_CHECKS
#endif /* JFFS2_DBG_SANITY_CHECKS */
#ifdef JFFS2_DBG_PARANOIA_CHECKS
#define check(sz)							\
#undef check
#if 0
#endif
#endif /* JFFS2_DBG_PARANOIA_CHECKS */
#if defined(JFFS2_DBG_DUMPS) || defined(JFFS2_DBG_PARANOIA_CHECKS)
#ifdef TEST_TOTLEN
#endif
#define JFFS2_BUFDUMP_BYTES_PER_LINE	32
#endif /* JFFS2_DBG_DUMPS || JFFS2_DBG_PARANOIA_CHECKS */
