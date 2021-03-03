#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#define CHECKSUM_OFFSET		(14*1024-4)
#define BUFSIZE			(16*1024)
#define FILE_PERM		(S_IRUSR | S_IWUSR | S_IRGRP \
