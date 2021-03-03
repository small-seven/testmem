#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/readlinkat.h"
#include "lapi/syscalls.h"
#define TEST_FILE	"test_file"
#define SYMLINK_FILE	"symlink_file"
#define BUFF_SIZE	256
