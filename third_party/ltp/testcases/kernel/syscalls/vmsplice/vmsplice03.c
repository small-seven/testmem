#define _GNU_SOURCE
#include "tst_test.h"
#include "lapi/fcntl.h"
#include "lapi/vmsplice.h"
#define TEST_BLOCK_SIZE (64*1024)	/* 64K */
