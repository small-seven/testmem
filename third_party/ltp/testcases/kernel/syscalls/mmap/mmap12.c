#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include "tst_test.h"
#define TEMPFILE        "mmapfile"
#define PATHLEN         256
#define MMAPSIZE        (1UL<<20)
