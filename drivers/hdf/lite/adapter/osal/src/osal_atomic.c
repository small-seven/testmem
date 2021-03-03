#include "osal_atomic.h"
#include "los_hwi.h"
#include "hdf_log.h"
#define HDF_LOG_TAG osal_atomic
#define OSAL_BITS_PER_LONG 32
#define OSAL_BIT_MASK(nr) (1UL << ((nr) % OSAL_BITS_PER_LONG))
#define OSAL_BIT_WORD(nr) ((nr) / OSAL_BITS_PER_LONG)
#define OSAL_BITOP_WORD(nr) ((nr) / OSAL_BITS_PER_LONG)
