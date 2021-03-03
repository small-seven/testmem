#define _KMEMUSER
#include <sys/types.h>
#include <stdio.h>
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include "test.h"
#include "tst_kernel.h"
#define AS_SVSM_VSEG_MAX	48UL
#define AS_SVSM_MMAP_MAX	16UL
#define EXTRA_VSEGS	2L
#define NUM_SEGS	(AS_SVSM_VSEG_MAX + EXTRA_VSEGS)
#define ERROR(M) (void)fprintf(stderr, "%s: errno = %d: " M "\n", TCID, \
#define NEG1	(char *)-1
