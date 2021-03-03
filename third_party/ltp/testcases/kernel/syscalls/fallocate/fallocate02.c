#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <endian.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <inttypes.h>
#include <sys/utsname.h>
#include <limits.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/fallocate.h"
#include "lapi/abisize.h"
#define BLOCKS_WRITTEN		12
#ifdef TEST_DEFAULT
# define DEFAULT_TEST_MODE	0
#else
# define DEFAULT_TEST_MODE	1
#endif
#define OFFSET			12
#define FNAMER			"test_file1"
#define FNAMEW			"test_file2"
#define BLOCK_SIZE		1024
#define MAX_FILESIZE            (LLONG_MAX / 1024)
#if defined(TST_ABI64) || _FILE_OFFSET_BITS == 64
#endif
