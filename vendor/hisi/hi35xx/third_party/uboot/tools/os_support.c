#include "compiler.h"
#ifdef __MINGW32__
#include "mingw_support.c"
#endif
#if defined(__APPLE__) && __DARWIN_C_LEVEL < 200809L
#include "getline.c"
#endif
