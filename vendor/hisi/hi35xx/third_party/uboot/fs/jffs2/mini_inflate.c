#include <config.h>
#include <jffs2/mini_inflate.h>
static inline void cramfs_memset(int *s, const int c, size n)
{
	n--;
	for (;n > 0; n--) s[n] = c;
	s[0] = c;
}
#if 0
#endif
