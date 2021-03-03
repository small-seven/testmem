#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <scsi/sg.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include "tst_test.h"
#define BUF_SIZE 128 * 4096
#define CMD_SIZE 6
