#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SCALEBITS 8
#define ONE_HALF  (1 << (SCALEBITS - 1))
#define FIX(x)    ((int) ((x) * (1 << SCALEBITS) + 0.5))
#define err_if(expr) do {                                              \
#define DEFAULT_WIDTH   352
#define DEFAULT_HEIGHT  288
#define DEFAULT_NB_PICT  50
