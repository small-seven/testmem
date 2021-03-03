#define _XOPEN_SOURCE 600
#define _GNU_SOURCE
#define MAX_ITERATIONS 250
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#define BIGSIZE 128*1024*1024
#define READSIZE 32*1024*1024
#define WRITESIZE 32*1024*1024
