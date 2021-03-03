#define PROGRAM_NAME    "ubicrc32"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <mtd/ubi-media.h>
#include <crc32.h>
#include "common.h"
#define BUFSIZE 4096
