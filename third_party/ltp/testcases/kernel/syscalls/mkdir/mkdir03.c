#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/mount.h>
#include "tst_test.h"
#define TST_EEXIST	"tst_eexist"
#define TST_ENOENT	"tst_enoent/tst"
#define TST_ENOTDIR_FILE "tst_enotdir"
#define TST_ENOTDIR_DIR	"tst_enotdir/tst"
#define MODE		0777
#define MNT_POINT	"mntpoint"
#define DIR_MODE	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
#define TST_EROFS      "mntpoint/tst_erofs"
