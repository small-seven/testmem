#define _GNU_SOURCE 1
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <inttypes.h>
#include "test.h"
#include "safe_macros.h"
#define SKIP 0x0c00
#if SKIP == F_RDLCK || SKIP== F_WRLCK
#error invalid value for SKIP, must be distinct from F_RDLCK and F_WRLCK
#endif
#ifndef S_ENFMT
#define S_ENFMT S_ISGID
#endif
#define NOBLOCK 2
#define WILLBLOCK 3
#define TIME_OUT 60
typedef struct {
	short a_type;
	short a_whence;
	long a_start;
	long a_len;
	short b_type;		/* SKIP means suppress fcntl call */
	short b_whence;
	long b_start;
	long b_len;
	short c_type;
	int c_whence;
	long c_start;
	long c_len;
	short c_flag;
} testcase;
#define FILEDATA	"ten bytes!"
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
