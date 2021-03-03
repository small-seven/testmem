#define PROGRAM_NAME "flash_torture"
#define KEEP_CONTENTS 0x01
#define RUN_FOREVER 0x02
#include <mtd/mtd-user.h>
#include <unistd.h>
#include <stdlib.h>
#include <libmtd.h>
#include <signal.h>
#include <getopt.h>
#include <stdio.h>
#include <fcntl.h>
#include "common.h"
