#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <utime.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include "test.h"
#include "safe_macros.h"
#define TEMP_FILE	"tmp_file"
#define FILE_MODE	S_IRUSR | S_IRGRP | S_IROTH
#define NEW_TIME	10000
