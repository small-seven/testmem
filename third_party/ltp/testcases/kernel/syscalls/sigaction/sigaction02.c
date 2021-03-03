#define DEBUG 0
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include "test.h"
#define SIGBAD 9999
#ifndef GLIBC_SIGACTION_BUG
#endif /* GLIBC_SIGACTION_BUG */
