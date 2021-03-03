#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#define PID_MAX_PATH "/proc/sys/kernel/pid_max"
#define PID_MAX 32768
#define RETURN 256
