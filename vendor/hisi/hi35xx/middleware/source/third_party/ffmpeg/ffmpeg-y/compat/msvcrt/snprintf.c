#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <string.h>
#include "compat/va_copy.h"
#include "libavutil/error.h"
#if defined(__MINGW32__)
#define EOVERFLOW EFBIG
#endif
