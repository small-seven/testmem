#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <sys/wait.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#define PERMS		0700
