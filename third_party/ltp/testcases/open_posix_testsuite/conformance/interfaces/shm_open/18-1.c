#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#define SHM_NAME "posixtest_18-1"
#define MOD_FLAGS     (S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)	/* -w?rw?r-? */
#define UMASK_FLAGS   (S_IRGRP | S_IWOTH)	/* --?r-?-w? */
#define ALL_MOD_FLAGS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | \
