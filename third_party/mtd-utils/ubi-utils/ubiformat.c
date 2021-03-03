#define MAX_CONSECUTIVE_BAD_BLOCKS 4
#define PROGRAM_NAME    "ubiformat"
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <libubi.h>
#include <libmtd.h>
#include <libscan.h>
#include <libubigen.h>
#include <mtd_swab.h>
#include <crc32.h>
#include "common.h"
