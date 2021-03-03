#define PROGRAM_NAME "nandpagetest"
#include <mtd/mtd-user.h>
#include <unistd.h>
#include <stdlib.h>
#include <libmtd.h>
#include <getopt.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "common.h"
#define KEEP_CONTENTS 0x01
#define SEED_SET 0x02
