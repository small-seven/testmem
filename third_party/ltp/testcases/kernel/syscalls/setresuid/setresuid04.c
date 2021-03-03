#define _GNU_SOURCE 1
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#include <pwd.h>
#include "compat_16.h"
