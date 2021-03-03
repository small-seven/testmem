#define PROGRAM_NAME "flash_stress"
#define KEEP_CONTENTS 0x01
#define COUNT_CHANGED 0x02
#define SEED_SET 0x04
#include <mtd/mtd-user.h>
#include <unistd.h>
#include <stdlib.h>
#include <libmtd.h>
#include <getopt.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "common.h"
