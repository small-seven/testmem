#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <linux/types.h>
#include <asm/getopt.h>
#include <asm/sections.h>
#include <asm/state.h>
#include <os.h>
#include <rtc_def.h>
void *os_malloc(size_t length)
{
	int page_size = getpagesize();
	struct os_mem_hdr *hdr;

	/*
	 * Use an address that is hopefully available to us so that pointers
	 * to this memory are fairly obvious. If we end up with a different
	 * address, that's fine too.
	 */
	hdr = mmap((void *)0x10000000, length + page_size,
		   PROT_READ | PROT_WRITE | PROT_EXEC,
		   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (hdr == MAP_FAILED)
		return NULL;
	hdr->length = length;

	return (void *)hdr + page_size;
}
void os_free(void *ptr)
{
	int page_size = getpagesize();
	struct os_mem_hdr *hdr;

	if (ptr) {
		hdr = ptr - page_size;
		munmap(hdr, hdr->length + page_size);
	}
}
void *os_realloc(void *ptr, size_t length)
{
	int page_size = getpagesize();
	struct os_mem_hdr *hdr;
	void *buf = NULL;

	if (length) {
		buf = os_malloc(length);
		if (!buf)
			return buf;
		if (ptr) {
			hdr = ptr - page_size;
			if (length > hdr->length)
				length = hdr->length;
			memcpy(buf, ptr, length);
		}
	}
	if (ptr)
		os_free(ptr);

	return buf;
}
#if defined(CLOCK_MONOTONIC) && defined(_POSIX_MONOTONIC_CLOCK)
#else
#endif
void os_dirent_free(struct os_dirent_node *node)
{
	struct os_dirent_node *next;

	while (node) {
		next = node->next;
		os_free(node);
		node = next;
	}
}
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
