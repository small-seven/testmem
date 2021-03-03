#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/param.h>
#include <string.h>		/* strcat */
#include "open_flags.h"
#define UNKNOWN_SYMBOL	"UNKNOWN"
#if O_NOCTTY
#endif
#if O_DSYNC
#endif
#if O_RSYNC
#endif
#if O_ASYNC
#endif
#if O_PTYIGN
#endif
#if O_NDELAY
#endif
#if O_RAW
#endif
#ifdef O_SSD
#endif
#if O_BIG
#endif
#if O_PLACE
#endif
#if O_RESTART
#endif
#if O_SFSXOP
#endif
#if O_SFS_DEFER_TM
#endif
#if O_WELLFORMED
#endif
#if O_LDRAW
#endif
#if O_T3D
#endif /* O_T3D */
#if O_PARALLEL
#endif /* O_PARALLEL */
#ifdef O_LARGEFILE
#endif
#ifdef O_DIRECT
#endif
#ifdef O_PRIV
#endif
#ifdef UNIT_TEST
#endif /* end of UNIT_TEST */
