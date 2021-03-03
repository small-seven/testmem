#define _GNU_SOURCE
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/poll.h>
#include "tst_test.h"
#include "lapi/fcntl.h"
#include "lapi/splice.h"
#include "lapi/vmsplice.h"
#define TEST_BLOCK_SIZE (1<<17)	/* 128K */
#define TESTFILE "vmsplice_test_file"
