#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <pwd.h>
#include "tst_test.h"
#define FILE_SIZE	 1024
#define TST_FILEREAD     "test_fileread"
#define TST_FILENOREAD   "test_filenoread"
#define READ_MODE        0666
#define NEW_MODE         0222
#define MASK             0777
