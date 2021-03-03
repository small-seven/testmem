#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "test.h"
#undef  BSIZE
#define BSIZE	4096
#define LEN	100
#define FAILED 0
#define PASSED 1
