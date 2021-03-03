#define _BSD_SOURCE
#include <string.h>
#include <stdint.h>
#include <limits.h>
#define ALIGN (sizeof(size_t)-1)
#define ONES ((size_t)-1/UCHAR_MAX)
#define HIGHS (ONES * (UCHAR_MAX/2+1))
#define HASZERO(x) ((x)-ONES & ~(x) & HIGHS)
#ifdef __GNUC__
	typedef size_t __attribute__((__may_alias__)) word;
	const word *ws;
	if (((uintptr_t)s & ALIGN) == ((uintptr_t)d & ALIGN)) {
		for (; ((uintptr_t)s & ALIGN) && n && (*d=*s); n--, s++, d++);
		if (n && *s) {
			wd=(void *)d; ws=(const void *)s;
			for (; n>=sizeof(size_t) && !HASZERO(*ws);
			       n-=sizeof(size_t), ws++, wd++) *wd = *ws;
			d=(void *)wd; s=(const void *)ws;
		}
#endif
