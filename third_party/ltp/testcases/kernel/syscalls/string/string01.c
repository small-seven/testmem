#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "test.h"
#define FAILED 0
#define PASSED 1
#define LONGSTR	(96*1024-1)
#define sign(x) ((x) < 0 ? -1 : ((x) > 0 ? 1 : 0))
