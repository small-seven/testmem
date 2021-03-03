#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "tst_test.h"
#define TESTFILE	"testfile"
#define TRUNC_LEN1	256
#define TRUNC_LEN2	512
#define FILE_SIZE	1024
