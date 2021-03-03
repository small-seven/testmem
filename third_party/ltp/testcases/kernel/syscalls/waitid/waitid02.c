#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/syscalls.h"
