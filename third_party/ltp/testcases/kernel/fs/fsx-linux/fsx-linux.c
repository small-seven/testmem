#include <sys/types.h>
#include <sys/stat.h>
#if defined(_UWIN) || defined(__linux__)
#include <sys/param.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#endif
#include <fcntl.h>
#include <sys/mman.h>
#ifndef MAP_FILE
#define MAP_FILE 0
#endif
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>
#define	LOGSIZE	1000
#define	OP_READ		1
#define OP_WRITE	2
#define OP_TRUNCATE	3
#define OP_CLOSEOPEN	4
#define OP_MAPREAD	5
#define OP_MAPWRITE	6
#define OP_SKIPPED	7
#define short_at(cp) ((unsigned short)((*((unsigned char *)(cp)) << 8) | \
