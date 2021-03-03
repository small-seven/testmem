#define LOG_CATEGORY LOGC_ALLOC
#include <common.h>
#include <malloc.h>
#include <mapmem.h>
#include <asm/io.h>
#if CONFIG_IS_ENABLED(SYS_MALLOC_SIMPLE)
void *calloc(size_t nmemb, size_t elem_size)
{
	size_t size = nmemb * elem_size;
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		return ptr;
	memset(ptr, '\0', size);

	return ptr;
}
#endif
