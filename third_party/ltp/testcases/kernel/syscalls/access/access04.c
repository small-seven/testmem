#include <errno.h>
#include <pwd.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <unistd.h>
#include "tst_test.h"
#define FNAME1	"accessfile1"
#define FNAME2	"accessfile2/accessfile2"
#define DNAME	"accessfile2"
#define SNAME1	"symlink1"
#define SNAME2	"symlink2"
#define MNT_POINT	"mntpoint"
