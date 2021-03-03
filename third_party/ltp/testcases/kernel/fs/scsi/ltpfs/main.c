#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <ftw.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/kd.h>
#include <linux/errno.h>
#include "Ltpfs.h"
#define M_2PI (M_PI*2)
#define MAXN 4096
#define MAXFSIZE 1024 * 192
#define FILE_CREATE_COUNT 256
#define FAIL 0
#define SUCCESS 1
#define MAXNUM   5000
#define BUFFSIZE 8192
#define AVEFSIZE (MAXFSIZE/2)
#define POOLDISKSPACE (AVEFSIZE*128)
#define MAXERROR  1024
#define FILES_ONLY 0x01
#define ALL        0x00
