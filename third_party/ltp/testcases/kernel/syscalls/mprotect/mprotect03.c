#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <limits.h>
#include <signal.h>
#include <sys/wait.h>
#include "test.h"
#include "safe_macros.h"
#ifndef PAGESIZE
#define PAGESIZE 4096
#endif
#define FAILED 1
