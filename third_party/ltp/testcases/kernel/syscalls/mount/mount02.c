#include <errno.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include "test.h"
#include "safe_macros.h"
#define DIR_MODE	(S_IRWXU | S_IRUSR | S_IXUSR | S_IRGRP | S_IXGRP)
#define FILE_MODE	(S_IRWXU | S_IRWXG | S_IRWXO)
