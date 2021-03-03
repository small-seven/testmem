#define _GNU_SOURCE
#include "config.h"
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#ifdef HAVE_MREMAP_FIXED
#else
#endif /* HAVE_MREMAP_FIXED */
