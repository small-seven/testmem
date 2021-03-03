#include <errno.h>
#include <string.h>
#include <limits.h>
#include <pwd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include "tst_test.h"
#define	TEST_FILE	"test_dir"
#define	NO_DIR		"testfile/testdir"
#define	NOT_DIR		"file1/testdir"
#define	TEST6_FILE	"dir6/file6"
#define	TEST7_FILE	"file7"
#define	TEST8_FILE	"mntpoint/tmp"
#define	MODE1		0444
#define	MODE2		0666
#if !defined(UCLINUX)
#endif
#if !defined(UCLINUX)
#endif
#if !defined(UCLINUX)
#endif
