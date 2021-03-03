#include <securec.h>
#include "osal_mem.h"
#include "hdf_log.h"
#include "hdf_sbuf.h"
#define HDF_SBUF_GROW_SIZE_DEFAULT 256
#define HDF_SBUF_MAX_SIZE (512 * 1024) // 512kB
#define HDF_SBUF_ALIGN 4
