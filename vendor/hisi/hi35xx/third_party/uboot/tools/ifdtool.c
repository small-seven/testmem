#include <assert.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/libfdt.h>
#include "ifdtool.h"
#undef DEBUG
#ifdef DEBUG
#define debug(fmt, args...)	printf(fmt, ##args)
#else
#define debug(fmt, args...)
#endif
#define FD_SIGNATURE		0x0FF0A55A
#define FLREG_BASE(reg)		((reg & 0x00000fff) << 12);
#define FLREG_LIMIT(reg)	(((reg & 0x0fff0000) >> 4) | 0xfff);
