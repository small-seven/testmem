#include <common.h>
#if !defined(CONFIG_SPL_BUILD)
#endif
void __aeabi_memcpy(void *dest, const void *src, size_t n)
{
	(void) memcpy(dest, src, n);
}
void __aeabi_memset(void *dest, size_t n, int c)
{
	(void) memset(dest, c, n);
}
