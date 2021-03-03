#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "jmem.h"
#define JMEM_ALLOCATOR_INTERNAL
#include "jmem-allocator-internal.h"
#include "test-common.h"
#define TEST_MAX_SUB_ITERS  1024
#define TEST_CHUNK_SIZE 8
#ifdef JMEM_STATS
#endif /* JMEM_STATS */
