#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include "tst_test.h"
#include "tst_safe_stdio.h"
#define CPUINFO_FILE "/proc/cpuinfo"
#define GDT_LEN 10
#define IDT_LEN 10
#ifdef __x86_64__
#else
#endif /* __x86_64__ */
