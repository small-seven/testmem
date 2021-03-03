#define _GNU_SOURCE
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "tst_test.h"
#include "lapi/splice.h"
#include "splice.h"
#define PIPE_MAX (64*1024)
