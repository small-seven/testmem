#include <config.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/ctype.h>
#include <malloc.h>
#ifndef __HAVE_ARCH_STRCPY
#endif
#ifndef __HAVE_ARCH_STRNCPY
#endif
#ifndef __HAVE_ARCH_STRLCPY
#endif
#ifndef __HAVE_ARCH_STRCAT
#endif
#ifndef __HAVE_ARCH_STRNCAT
#endif
#ifndef __HAVE_ARCH_STRCMP
#endif
#ifndef __HAVE_ARCH_STRNCMP
#endif
#ifndef __HAVE_ARCH_STRCHR
#endif
#ifndef __HAVE_ARCH_STRRCHR
#endif
#ifndef __HAVE_ARCH_STRLEN
#endif
#ifndef __HAVE_ARCH_STRNLEN
#endif
#ifndef __HAVE_ARCH_STRCSPN
#endif
#ifndef __HAVE_ARCH_STRDUP
#endif
#ifndef __HAVE_ARCH_STRSPN
#endif
#ifndef __HAVE_ARCH_STRPBRK
#endif
#ifndef __HAVE_ARCH_STRTOK
#endif
#ifndef __HAVE_ARCH_STRSEP
#endif
#ifndef __HAVE_ARCH_STRSWAB
#endif
#ifndef __HAVE_ARCH_MEMSET
void * memset(void * s,int c,size_t count)
{
	unsigned long *sl = (unsigned long *) s;
	char *s8;

#if !CONFIG_IS_ENABLED(TINY_MEMSET)
	unsigned long cl = 0;
	int i;

	/* do it one word at a time (32 bits or 64 bits) while possible */
	if ( ((ulong)s & (sizeof(*sl) - 1)) == 0) {
		for (i = 0; i < sizeof(*sl); i++) {
			cl <<= 8;
			cl |= c & 0xff;
		}
		while (count >= sizeof(*sl)) {
			*sl++ = cl;
			count -= sizeof(*sl);
		}
	}
#endif	/* fill 8 bits at a time */
	s8 = (char *)sl;
	while (count--)
		*s8++ = c;

	return s;
}
#endif
#ifndef __HAVE_ARCH_MEMCPY
void * memcpy(void *dest, const void *src, size_t count)
{
	unsigned long *dl = (unsigned long *)dest, *sl = (unsigned long *)src;
	char *d8, *s8;

	if (src == dest)
		return dest;

	/* while all data is aligned (common case), copy a word at a time */
	if ( (((ulong)dest | (ulong)src) & (sizeof(*dl) - 1)) == 0) {
		while (count >= sizeof(*dl)) {
			*dl++ = *sl++;
			count -= sizeof(*dl);
		}
	}
	/* copy the reset one byte at a time */
	d8 = (char *)dl;
	s8 = (char *)sl;
	while (count--)
		*d8++ = *s8++;

	return dest;
}
#endif
#ifndef __HAVE_ARCH_MEMMOVE
void * memmove(void * dest,const void *src,size_t count)
{
	char *tmp, *s;

	if (dest <= src) {
		memcpy(dest, src, count);
	} else {
		tmp = (char *) dest + count;
		s = (char *) src + count;
		while (count--)
			*--tmp = *--s;
		}

	return dest;
}
#endif
#ifndef __HAVE_ARCH_MEMCMP
int memcmp(const void * cs,const void * ct,size_t count)
{
	const unsigned char *su1, *su2;
	int res = 0;

	for( su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
		if ((res = *su1 - *su2) != 0)
			break;
	return res;
}
#endif
#ifndef __HAVE_ARCH_MEMSCAN
#endif
#ifndef __HAVE_ARCH_STRSTR
#endif
#ifndef __HAVE_ARCH_MEMCHR
void *memchr(const void *s, int c, size_t n)
{
	const unsigned char *p = s;
	while (n-- != 0) {
		if ((unsigned char)c == *p++) {
			return (void *)(p-1);
		}
	}
	return NULL;
}
#endif
#ifndef __HAVE_ARCH_MEMCHR_INV
#endif
