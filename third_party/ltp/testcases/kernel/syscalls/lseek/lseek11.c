#define _GNU_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "tst_test.h"
#include "tst_safe_prw.h"
#include "lapi/seek.h"
#define UNIT_COUNT   3
#define UNIT_BLOCKS  10
#define FILE_BLOCKS  (UNIT_BLOCKS * UNIT_COUNT)
