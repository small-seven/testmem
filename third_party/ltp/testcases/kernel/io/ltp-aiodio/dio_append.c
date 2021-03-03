#define _GNU_SOURCE
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <limits.h>
#include "test.h"
#define NUM_CHILDREN 8
#include "common_checkzero.h"
