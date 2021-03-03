#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#define BUFSIZE			(16*1024)
#define IMG_SIZE		(16*1024)
#define SPL_HEADER_SIZE		16
#define FILE_PERM		(S_IRUSR | S_IWUSR | S_IRGRP \
#define SPL_HEADER		"S5PC210 HEADER  "
