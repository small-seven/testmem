#include "error_private.h"
#include "zstd_internal.h" /* declaration of ZSTD_isError, ZSTD_getErrorName, ZSTD_getErrorCode, ZSTD_getErrorString, ZSTD_versionNumber */
#include <linux/kernel.h>
#define stack_push(stack, size)                                 \
void ZSTD_free(void *ptr, ZSTD_customMem customMem)
{
	if (ptr != NULL)
		customMem.customFree(customMem.opaque, ptr);
}
