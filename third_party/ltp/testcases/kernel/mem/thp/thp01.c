#include <errno.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "tst_test.h"
#include "mem.h"
#include "tst_minmax.h"
#define ARGS_SZ	(256 * 32)
