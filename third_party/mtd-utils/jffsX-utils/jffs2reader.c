#define PROGRAM_NAME "jffs2reader"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <zlib.h>
#include "mtd/jffs2-user.h"
#include "common.h"
#define SCRATCH_SIZE (5*1024*1024)
#define ADD_BYTES(p, n)		((p) = (typeof(p))((char *)(p) + (n)))
#define DIRENT_INO(dirent) ((dirent) !=NULL ? je32_to_cpu((dirent)->ino) : 0)
#define DIRENT_PINO(dirent) ((dirent) !=NULL ? je32_to_cpu((dirent)->pino) : 0)
#define TYPEINDEX(mode) (((mode) >> 12) & 0x0f)
#define TYPECHAR(mode)  ("0pcCd?bB-?l?s???" [TYPEINDEX(mode)])
