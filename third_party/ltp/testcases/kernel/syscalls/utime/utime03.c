#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <utime.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include "test.h"
#include "safe_macros.h"
#define TEMP_FILE	"tmp_file"
#define FILE_MODE	S_IRWXU | S_IRGRP | S_IWGRP| S_IROTH | S_IWOTH
#define LTPUSER1	"nobody"
#define LTPUSER2	"bin"
