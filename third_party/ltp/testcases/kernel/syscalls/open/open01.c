#define _GNU_SOURCE		/* for O_DIRECTORY */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "tst_test.h"
#define TEST_FILE	"testfile"
#define TEST_DIR	"testdir"
