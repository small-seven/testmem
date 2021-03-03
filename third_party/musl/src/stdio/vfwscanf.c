#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <limits.h>
#include <string.h>
#include "stdio_impl.h"
#include "shgetc.h"
#include "intscan.h"
#include "floatscan.h"
#define SIZE_hh -2
#define SIZE_h  -1
#define SIZE_def 0
#define SIZE_l   1
#define SIZE_L   2
#define SIZE_ll  3
#if 1
#undef getwc
#define getwc(f) \
#undef ungetwc
#define ungetwc(c,f) \
#endif
