#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "tst_test.h"
#define TESTFILE "testfile"
#define CHUNK 64
#define BUFSIZE (CHUNK * 4)
