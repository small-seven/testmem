#include "includes.h"
#include <time.h>
#include <sys/wait.h>
#ifdef ANDROID
#include <sys/capability.h>
#include <sys/prctl.h>
#include <private/android_filesystem_config.h>
#endif /* ANDROID */
#ifdef __MACH__
#include <CoreServices/CoreServices.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#endif /* __MACH__ */
#include "os.h"
#include "common.h"
#ifdef WPA_TRACE
#include "wpa_debug.h"
#include "trace.h"
#include "list.h"
#define ALLOC_MAGIC 0xa84ef1b2
#define FREED_MAGIC 0x67fd487a
#endif /* WPA_TRACE */
#ifndef __MACH__
#if defined(CLOCK_BOOTTIME)
#elif defined(CLOCK_MONOTONIC)
#else
#endif
#ifdef CLOCK_BOOTTIME
#endif
#ifdef CLOCK_MONOTONIC
#endif
#else /* __MACH__ */
#endif /* __MACH__ */
#ifdef __APPLE__
#include <fcntl.h>
#else /* __APPLE__ */
#define os_daemon daemon
#endif /* __APPLE__ */
#if defined(__uClinux__) || defined(__sun__)
#else /* defined(__uClinux__) || defined(__sun__) */
#endif /* defined(__uClinux__) || defined(__sun__) */
#ifdef ANDROID
#ifdef ANDROID_SETGROUPS_OVERRIDE
#else /* ANDROID_SETGROUPS_OVERRIDE */
#endif /* ANDROID_SETGROUPS_OVERRIDE */
#endif /* ANDROID */
void os_program_deinit(void)
{
#ifdef WPA_TRACE
	struct os_alloc_trace *a;
	unsigned long total = 0;
	dl_list_for_each(a, &alloc_list, struct os_alloc_trace, list) {
		total += a->len;
		if (a->magic != ALLOC_MAGIC) {
			wpa_printf(MSG_INFO, "MEMLEAK[%p]: invalid magic 0x%x "
				   "len %lu",
				   a, a->magic, (unsigned long) a->len);
			continue;
		}
		wpa_printf(MSG_INFO, "MEMLEAK[%p]: len %lu",
			   a, (unsigned long) a->len);
		wpa_trace_dump("memleak", a);
	}
	if (total)
		wpa_printf(MSG_INFO, "MEMLEAK: total %lu bytes",
			   (unsigned long) total);
	wpa_trace_deinit();
#endif /* WPA_TRACE */
}
#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__) || \
#else
#endif
#ifdef __linux__
#else /* !__linux__ */
#ifdef F_FULLFSYNC
#else /* F_FULLFSYNC */
#endif /* F_FULLFSYNC */
#endif /* __linux__ */
#ifndef WPA_TRACE
void * os_zalloc(size_t size)
{
	return calloc(1, size);
}
#endif /* WPA_TRACE */
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

	if (r && src)
		os_memcpy(r, src, len);
	return r;
}
#ifdef WPA_TRACE
#if defined(WPA_TRACE_BFD) && defined(CONFIG_TESTING_OPTIONS)
#else
#endif
void * os_malloc(size_t size)
{
	struct os_alloc_trace *a;

	if (testing_fail_alloc())
		return NULL;

	a = malloc(sizeof(*a) + size);
	if (a == NULL)
		return NULL;
	a->magic = ALLOC_MAGIC;
	dl_list_add(&alloc_list, &a->list);
	a->len = size;
	wpa_trace_record(a);
	return a + 1;
}
void * os_realloc(void *ptr, size_t size)
{
	struct os_alloc_trace *a;
	size_t copy_len;
	void *n;

	if (ptr == NULL)
		return os_malloc(size);

	a = (struct os_alloc_trace *) ptr - 1;
	if (a->magic != ALLOC_MAGIC) {
		wpa_printf(MSG_INFO, "REALLOC[%p]: invalid magic 0x%x%s",
			   a, a->magic,
			   a->magic == FREED_MAGIC ? " (already freed)" : "");
		wpa_trace_show("Invalid os_realloc() call");
		abort();
	}
	n = os_malloc(size);
	if (n == NULL)
		return NULL;
	copy_len = a->len;
	if (copy_len > size)
		copy_len = size;
	os_memcpy(n, a + 1, copy_len);
	os_free(ptr);
	return n;
}
void os_free(void *ptr)
{
	struct os_alloc_trace *a;

	if (ptr == NULL)
		return;
	a = (struct os_alloc_trace *) ptr - 1;
	if (a->magic != ALLOC_MAGIC) {
		wpa_printf(MSG_INFO, "FREE[%p]: invalid magic 0x%x%s",
			   a, a->magic,
			   a->magic == FREED_MAGIC ? " (already freed)" : "");
		wpa_trace_show("Invalid os_free() call");
		abort();
	}
	dl_list_del(&a->list);
	a->magic = FREED_MAGIC;

	wpa_trace_check_ref(ptr);
	free(a);
}
void * os_zalloc(size_t size)
{
	void *ptr = os_malloc(size);
	if (ptr)
		os_memset(ptr, 0, size);
	return ptr;
}
#endif /* WPA_TRACE */
