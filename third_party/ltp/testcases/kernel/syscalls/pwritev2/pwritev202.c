#define _GNU_SOURCE
#include <sys/uio.h>
#include <unistd.h>
#include "tst_test.h"
#include "lapi/pwritev2.h"
#define CHUNK	64
