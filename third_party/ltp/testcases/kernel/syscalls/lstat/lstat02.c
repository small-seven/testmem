#include <errno.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "tst_test.h"
#define MODE_RWX	0777
#define MODE_RW0	0666
#define TEST_DIR	"test_dir"
#define TEST_FILE	"test_file"
#define TEST_ELOOP	"/test_eloop"
#define TEST_ENOENT	""
#define TEST_EACCES	TEST_DIR"/test_eacces"
#define TEST_ENOTDIR	TEST_FILE"/test_enotdir"
