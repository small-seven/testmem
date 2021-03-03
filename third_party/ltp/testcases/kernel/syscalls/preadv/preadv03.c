#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>
#include <sys/ioctl.h>
#include <sys/mount.h>
#include "tst_test.h"
#include "preadv.h"
#define MNTPOINT	"mntpoint"
#define FNAME	MNTPOINT"/file"
