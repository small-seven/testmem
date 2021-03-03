#include <sys/types.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/abisize.h"
#ifdef __ia64__
# define HIGH_ADDR (void *)(0xa000000000000000UL)
#else
# define HIGH_ADDR (void *)(-page_size)
#endif
#ifdef TST_ABI32
#endif
