#include <pwd.h>
#include <errno.h>
#include "tst_test.h"
#define MODE_RWX	(S_IRWXU|S_IRWXG|S_IRWXO)
#define FILE_MODE	(S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
#define DIR_TEMP	"testdir_1"
#define TEST_FILE1	"tfile_1"
#define TEST_FILE2	"testdir_1/tfile_2"
#define TEST_FILE3	"t_file/tfile_3"
#define TEST_FILE4	"test_file4"
#define MNT_POINT	"mntpoint"
#define DIR_MODE	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
