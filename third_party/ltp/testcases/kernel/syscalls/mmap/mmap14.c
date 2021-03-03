#include <stdio.h>
#include <sys/mman.h>
#include "test.h"
#define TEMPFILE        "mmapfile"
#define MMAPSIZE        (1UL<<20)
#define LINELEN         256
