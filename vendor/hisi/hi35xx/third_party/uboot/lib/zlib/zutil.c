#include "zutil.h"
#ifndef NO_DUMMY_DECL
#endif
#ifdef DEBUG
#ifndef verbose
#define verbose 0
#endif
#endif
#ifndef MY_ZCALLOC /* Any system without a special alloc function */
#ifdef __UBOOT__
#include <malloc.h>
#else
#ifndef STDC
#endif
#endif
voidpf zcalloc(voidpf opaque, unsigned items, unsigned size)
{
	if (opaque)
		items += size - size; /* make compiler happy */
	return sizeof(uInt) > 2 ? (voidpf)malloc(items * size) :
		(voidpf)calloc(items, size);
}
void  zcfree(voidpf opaque, voidpf ptr, unsigned nb)
{
	free(ptr);
	if (opaque)
		return; /* make compiler happy */
}
#endif /* MY_ZCALLOC */
