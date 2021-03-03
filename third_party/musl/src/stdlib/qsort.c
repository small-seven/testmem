#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "atomic.h"
#define ntz(x) a_ctz_l((x))
typedef int (*cmpfun)(const void *, const void *);

static inline int pntz(size_t p[2]) {
	int r = ntz(p[0] - 1);
	if(r != 0 || (r = 8*sizeof(size_t) + ntz(p[1])) != 8*sizeof(size_t)) {
		return r;
	}
