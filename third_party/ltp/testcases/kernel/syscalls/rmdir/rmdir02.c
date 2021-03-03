#include <errno.h>
#include "tst_test.h"
#define DIR_MODE	(S_IRWXU | S_IRWXG | S_IRWXO)
#define FILE_MODE	(S_IRWXU | S_IRWXG | S_IRWXO)
#define TESTDIR		"testdir"
#define TESTDIR2	"nosuchdir/testdir2"
#define TESTDIR3	"testfile2/testdir3"
#define TESTDIR4	"/loopdir"
#define MNT_POINT	"mntpoint"
#define TESTDIR5	"mntpoint/dir"
#define TESTFILE    "testdir/testfile"
#define TESTFILE2   "testfile2"
