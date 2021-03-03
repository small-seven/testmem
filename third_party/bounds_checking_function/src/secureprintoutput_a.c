#define SECUREC_FORMAT_OUTPUT_INPUT 1
#ifdef SECUREC_FOR_WCHAR
#undef SECUREC_FOR_WCHAR
#endif
#include "secureprintoutput.h"
#if SECUREC_WARP_OUTPUT
#define SECUREC_FORMAT_FLAG_TABLE_SIZE 128
#else
#if SECUREC_IN_KERNEL
#include <linux/ctype.h>
#endif
#ifndef EOF
#define EOF (-1)
#endif
#include "output.inl"
#endif
