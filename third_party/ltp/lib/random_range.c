#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "random_range.h"
#if CRAY
#else
#endif
#if CRAY || (_MIPS_SZLONG == 64)
#else
#endif
#if DEBUG
#endif
#ifndef CRAY
#else
#endif /* if CRAY */
#if RANDOM_BIT_UNITTEST
#endif /* end if RANDOM_BIT_UNITTEST */
#if UNIT_TEST
#define PARTNUM	10		/* used to determine even distribution of random numbers */
#define MEG  1024*1024*1024
#define GIG 1073741824
#if CRAY
#else
#endif
#if CRAY || (_MIPS_SZLONG == 64)
#else
#endif
#endif
