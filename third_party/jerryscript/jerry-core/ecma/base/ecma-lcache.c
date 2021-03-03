#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-lcache.h"
#include "jcontext.h"
#if ENABLED (JERRY_LCACHE)
#if ENABLED (JERRY_CPOINTER_32_BIT)
#define ECMA_LCACHE_HASH_BITSHIFT_INDEX (2 * JMEM_ALIGNMENT_LOG)
#else /* !ENABLED (JERRY_CPOINTER_32_BIT) */
#define ECMA_LCACHE_HASH_BITSHIFT_INDEX 0
#endif /* ENABLED (JERRY_CPOINTER_32_BIT) */
#define ECMA_LCACHE_HASH_MASK ((ECMA_LCACHE_HASH_ROWS_COUNT - 1) << ECMA_LCACHE_HASH_BITSHIFT_INDEX)
#define ECMA_LCACHE_HASH_ENTRY_ID_SHIFT (8 * sizeof (jmem_cpointer_t))
#define ECMA_LCACHE_CREATE_ID(object_cp, name_cp) \
#endif /* ENABLED (JERRY_LCACHE) */
