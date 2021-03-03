#include "includes.h"
#include <time.h>
#include <winsock2.h>
#include <wincrypt.h>
#include "os.h"
#include "common.h"
#define EPOCHFILETIME (116444736000000000ULL)
#ifdef _WIN32_WCE
#else /* _WIN32_WCE */
#endif /* _WIN32_WCE */
#ifdef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
void os_program_deinit(void)
{
#ifdef CONFIG_NATIVE_WINDOWS
	WSACleanup();
#endif /* CONFIG_NATIVE_WINDOWS */
}
void * os_zalloc(size_t size)
{
	return calloc(1, size);
}
int os_memcmp_const(const void *a, const void *b, size_t len)
{
	const u8 *aa = a;
	const u8 *bb = b;
	size_t i;
	u8 res;

	for (res = 0, i = 0; i < len; i++)
		res |= aa[i] ^ bb[i];

	return res;
}
void * os_memdup(const void *src, size_t len)
{
	void *r = os_malloc(len);

	if (r)
		os_memcpy(r, src, len);
	return r;
}
