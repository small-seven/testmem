#include "yportenv.h"
#include <sort.h>
#define swapcode(TYPE, parmi, parmj, n) do {		\
#define SWAPINIT(a, es) swaptype = ((char *)a - (char *)0) % sizeof(long) || \
#define yswap(a, b) do {					\
#define vecswap(a, b, n)	if ((n) > 0) swapfunc(a, b, n, swaptype)
#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif
