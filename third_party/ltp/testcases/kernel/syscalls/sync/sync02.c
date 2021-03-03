#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include "test.h"
#define TEMP_FILE	"temp_file"
#define FILE_MODE       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
