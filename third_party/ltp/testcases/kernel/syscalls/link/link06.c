#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include "test.h"
#include "safe_macros.h"
#define NOBODY_USER	99
#define MODE_TO S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IXGRP|S_IXOTH|S_IROTH
#define OLDPATH "oldpath"
#define NEWPATH "newpath"
