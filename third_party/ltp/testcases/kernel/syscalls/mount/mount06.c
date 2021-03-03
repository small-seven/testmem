#include <errno.h>
#include <sys/mount.h>
#include <unistd.h>
#include <fcntl.h>
#include "test.h"
#include "safe_macros.h"
#ifndef MS_MOVE
#define MS_MOVE	8192
#endif
#ifndef MS_PRIVATE
#define MS_PRIVATE	(1 << 18)
#endif
#define MNTPOINT_SRC	"mnt_src"
#define MNTPOINT_DES	"mnt_des"
#define LINELENGTH	256
#define DIR_MODE	(S_IRWXU | S_IRUSR | S_IXUSR | S_IRGRP | S_IXGRP)
