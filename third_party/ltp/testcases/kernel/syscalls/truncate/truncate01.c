#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <inttypes.h>
#include "test.h"
#include "safe_macros.h"
#define TESTFILE	"testfile"	/* file under test */
#define FILE_MODE	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define BUF_SIZE	256	/* buffer size */
#define FILE_SIZE	1024	/* test file size */
#define TRUNC_LEN	256	/* truncation length */
