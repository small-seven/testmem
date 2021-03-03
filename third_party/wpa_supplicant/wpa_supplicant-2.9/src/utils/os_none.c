#include "includes.h"
#include "os.h"
void os_program_deinit(void)
{
}
void * os_zalloc(size_t size)
{
	return NULL;
}
void * os_memdup(const void *src, size_t n)
{
	return NULL;
}
#ifdef OS_NO_C_LIB_DEFINES
void * os_malloc(size_t size)
{
	return NULL;
}
void * os_realloc(void *ptr, size_t size)
{
	return NULL;
}
void os_free(void *ptr)
{
}
void * os_memcpy(void *dest, const void *src, size_t n)
{
	return dest;
}
void * os_memmove(void *dest, const void *src, size_t n)
{
	return dest;
}
void * os_memset(void *s, int c, size_t n)
{
	return s;
}
int os_memcmp(const void *s1, const void *s2, size_t n)
{
	return 0;
}
int os_memcmp_const(const void *a, const void *b, size_t len)
{
	return 0;
}
#endif /* OS_NO_C_LIB_DEFINES */
