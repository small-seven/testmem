#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <pwd.h>
#include <sys/resource.h>
#include "test.h"
#include "safe_macros.h"
#define INV_SYNC	-1
#define TEMPFILE	"msync_file"
#define BUF_SIZE	256
