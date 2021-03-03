#include <fcntl.h>
#include <getopt.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "test.h"
#define BLOCKSIZE (1024*1024)
#define FILE_OUT    "fileout"
#define FILE_MODE   0644
#define MAX_FILENAME_LEN 1024
