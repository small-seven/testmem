#define PROGRAM_NAME    "ubinize"
#include <sys/stat.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <fcntl.h>
#include <mtd/ubi-media.h>
#include <libubigen.h>
#include <libiniparser.h>
#include <libubi.h>
#include "common.h"
