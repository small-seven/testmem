#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>
#include <sys/file.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/param.h>
#include <sys/signal.h>
#include <sys/statfs.h>
#include <sys/vfs.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>
#include "dataascii.h"
#include "random_range.h"
#include "databin.h"
#include "open_flags.h"
#include "forker.h"
#include "file_lock.h"
#ifdef CRAY
#include <sys/panic.h>
#include <sys/category.h>
#endif
#include "test.h"
#ifndef linux
#endif /* !linux */
#define exit(x) myexit(x)
#define NEWIO	1		/* Use the tlibio.c functions */
#ifndef NEWIO
#define NEWIO	0		/* specifies to use original iowrite.c */
#else
#include "tlibio.h"
#endif
#ifndef PATH_MAX
#define PATH_MAX	1023
#endif
#define DEF_DIR		"."
#define DEF_FILE	"gf"
#ifdef O_LARGEFILE
#else
#warning O_LARGEFILE is not defined!
#endif
#define MAX_FC_READ	196608	/* 4096 * 48 - 48 blocks */
#define PATTERN_ASCII	1	/* repeating alphabet letter pattern */
#define PATTERN_PID	2	/* <pid><words byte offset><pid> */
#define PATTERN_OFFSET	3	/* Like PATTERN_PID but has a fixed number */
#define PATTERN_ALT	4	/* alternating bit pattern (i.e. 0x5555555...) */
#define PATTERN_CHKER	5	/* checkerboard pattern (i.e. 0xff00ff00ff00...) */
#define PATTERN_CNTING  6	/* counting pattern (i.e. 0 - 07, 0 - 07, ...) */
#define PATTERN_ONES	7	/* all bits set (i.e. 0xffffffffffffff...) */
#define PATTERN_ZEROS	8	/* all bits cleared (i.e. 0x000000000...) */
#define PATTERN_RANDOM	9	/* random integers - can not be checked */
#define STATIC_NUM	221849	/* used instead of pid when PATTERN_OFFSET */
#define MODE_RAND_SIZE	1	/* random write and trunc */
#define MODE_RAND_LSEEK	2	/* random lseek before write */
#define MODE_GROW_BY_LSEEK 4	/* lseek beyond end of file then write a byte */
#define RANDOM_OPEN	999876	/* if Open_flags set to this value, open flags */
#define MODE_FIFO	S_IFIFO	/* defined in stat.h  0010000 */
#ifdef CRAY
#else
#endif
#ifdef CRAY
#if ALLOW_O_WELLFORMED
#if O_PARALLEL
#endif /* O_PARALLEL */
#endif
#else /* CRAY */
#endif /* CRAY */
#define REXEC_INIT	0	/* don't do re-exec of childern */
#define REXEC_DOIT	1	/* Do re-exec of childern */
#define REXEC_DONE	2	/* We've already been re-exec'ed */
#ifndef BSIZE
#ifdef CRAY
#define BSIZE	1024
#else
#define BSIZE	512
#endif /* CRAY */
#endif /* BSIZE */
#define USECS_PER_SEC	1000000	/* microseconds per second */
#define LKLVL0		1	/* file lock around write/read/trunc */
#define LKLVL1		2	/* file lock after open to before close */
#define LSK_EOF       	    -1	/* set fptr up to EOF */
#define LSK_EOFPLUSGROW	    -2	/* set fptr up to EOF + grow - leave whole */
#define LSK_EOFMINUSGROW    -3	/* set fptr up to EOF-grow - no grow */
#ifndef linux
#endif
#ifdef CRAY
#endif
#if NEWIO
#else
#endif
#ifdef linux
#else
#endif
#ifdef CRAY
#else
#endif
#if CRAY
#endif
#if NEWIO
#else
#endif
#ifndef linux
#endif
#if CRAY
#else
#endif
#ifndef linux
#endif
#ifdef CRAY
#else
#endif
#ifndef linux
#endif
#ifdef CRAY
#endif /* CRAY */
#ifdef SIGCKPT
#endif /* SIGCKPT */
#ifdef SIGRESTART
#endif /* SIGRESTART */
#ifdef sgi
#else
#endif
#ifndef sgi
#endif
#if CRAY
#else
#endif
#ifdef CRAY
#endif
# truncate file by 408990 bytes.  Done to 200 files in dir1.\n\
# rand io types doing a trunc every 5 iterations, with unlinks.\n\
# random open flags, rand io types doing a trunc every 10 iterations.\n\
#if NEWIO
#else
#endif
#if NEWIO
#else
#endif
#if NEWIO
#if defined(sgi) || defined(__linux__)
#endif /* sgi __linux__ */
#endif
#ifdef CRAY
#endif
#ifdef CRAY
#endif
#ifdef CRAY
#endif
#ifdef CRAY
#else
#endif
#ifdef CRAY
#else
#endif
#if NEWIO
#else
#endif
#if NEWIO
#else
#endif
#if NEWIO
#else
#endif
#ifndef linux
#ifdef CRAY
#endif
#ifdef sgi
#endif
#endif
