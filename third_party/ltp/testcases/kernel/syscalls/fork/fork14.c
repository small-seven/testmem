#include <sys/mman.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/abisize.h"
#define GB		(1024 * 1024 * 1024L)
#define LARGE		(16 * 1024)
#define EXTENT		(16 * 1024 + 10)
#ifdef TST_ABI32
#endif
