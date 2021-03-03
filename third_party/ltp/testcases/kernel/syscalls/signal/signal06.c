#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/mman.h>
#include <pthread.h>
#include <assert.h>
#include <errno.h>
#include "test.h"
#include "lapi/syscalls.h"
#if __x86_64__
#define LOOPS 30000
#define VALUE 123.456
#else
#endif
