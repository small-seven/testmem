#include <config.h>
#include "bzlib_private.h"
#define WEIGHTOF(zz0)  ((zz0) & 0xffffff00)
#define DEPTHOF(zz1)   ((zz1) & 0x000000ff)
#define MYMAX(zz2,zz3) ((zz2) > (zz3) ? (zz2) : (zz3))
#define ADDWEIGHTS(zw1,zw2)                           \
#define UPHEAP(z)                                     \
#define DOWNHEAP(z)                                   \
