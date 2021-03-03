#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <limits.h>
#include "test.h"
#include "safe_macros.h"
#define FIFONAME "fifo"
