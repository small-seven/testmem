#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/poll.h>
#include <limits.h>
#define SAFE_FREE(p) { if (p) { free(p); (p)=NULL; } }
#define DATASIZE 100
#ifndef __ia64__
#endif
