#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libubi.h>
#include <mtd/ubi-user.h>
#define PROGRAM_NAME "io_update"
#include "common.h"
#include "helpers.h"
#define SEQUENCES(io, s) {           \
#define SEQ_SZ 21
