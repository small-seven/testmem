#define _GNU_SOURCE 1
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "pidns_helper.h"
#include "test.h"
#define CHILD_PID       1
#define PARENT_PID      0
