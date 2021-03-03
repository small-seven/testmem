#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <linux/mman.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include "lapi/mlock2.h"
#define PAGES	8
#define HPAGES	(PAGES / 2)
