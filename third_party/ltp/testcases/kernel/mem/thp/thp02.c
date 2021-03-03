#define _GNU_SOURCE
#include "config.h"
#include <sys/types.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mem.h"
#ifdef HAVE_MREMAP_FIXED
#else
#endif /* HAVE_MREMAP_FIXED */
