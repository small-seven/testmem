#define PROGRAM_NAME "libubigen"
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <mtd/ubi-media.h>
#include <mtd_swab.h>
#include <libubigen.h>
#include <crc32.h>
#include "common.h"
