#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#define MAP_FLAGS		(MAP_PRIVATE|MAP_ANONYMOUS|MAP_LOCKED)
#define LOOP			40
#define FORKED_PROC_COUNT	10
