#include <common.h>
int memcmp(const void *s1, const void *s2, size_t n)
{
	const u8 *pos1 = s1;
	const u8 *pos2 = s2;

	for (; n; --n) {
		if (*pos1 != *pos2)
			return *pos1 - *pos2;
		++pos1;
		++pos2;
	}
	return 0;
}
void *memmove(void *dest, const void *src, size_t n)
{
	u8 *d = dest;
	const u8 *s = src;

	if (d >= s) {
		for (; n; --n)
			*d++ = *s++;
	} else {
		d += n;
		s += n;
		for (; n; --n)
			*--d = *--s;
	}
	return dest;
}
void *memcpy(void *dest, const void *src, size_t n)
{
	return memmove(dest, src, n);
}
void *memset(void *s, int c, size_t n)
{
	u8 *d = s;

	for (; n; --n)
		*d++ = c;
	return s;
}
