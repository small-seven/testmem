#include <sys/types.h>
#include <sys/stat.h>
#include <lapi/fnmatch.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fnmatch.h>
#include <semaphore.h>
#include <ctype.h>
#include <pwd.h>
#include <grp.h>
#include "tst_test.h"
#define QUEUE_SIZE 16384
#define BUFFER_SIZE 1024
#define MAX_PATH 4096
#define MAX_DISPLAY 40
static void queue_destroy(struct queue *q, int is_worker)
{
	if (is_worker)
		sem_destroy(&q->sem);

	SAFE_MUNMAP(q, sizeof(*q));
}
