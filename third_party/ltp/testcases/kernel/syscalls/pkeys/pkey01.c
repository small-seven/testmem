#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "pkey.h"
#define TEST_FILE "pkey_testfile"
#define STR "abcdefghijklmnopqrstuvwxyz12345\n"
#define PATH_VM_NRHPS "/proc/sys/vm/nr_hugepages"
