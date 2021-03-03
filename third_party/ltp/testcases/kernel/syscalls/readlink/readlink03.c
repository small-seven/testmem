#include <pwd.h>
#include <errno.h>
#include <string.h>
#include "tst_test.h"
#define DIR_TEMP	"test_dir_1"
#define TEST_FILE1	"test_dir_1/test_file_1"
#define SYM_FILE1	"test_dir_1/slink_file_1"
#define TEST_FILE2	"test_file_2"
#define SYM_FILE2	"slink_file_2"
#define TEST_FILE3	"test_file_3"
#define SYM_FILE3	"test_file_3/slink_file_3"
#define ELOOPFILE	"/test_eloop"
#define TESTFILE	"test_file"
#define SYMFILE		"slink_file"
