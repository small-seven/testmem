#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include "test.h"
#include "safe_macros.h"
#define  TESTFILE	"testfile"
#define  SYMFILE	"slink_file"
#define FILE_MODE       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
