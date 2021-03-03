#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#ifdef CRAY
#include <sys/iosw.h>
#endif
#ifdef sgi
#include <aio.h>		/* for aio_read,write */
#include <inttypes.h>		/* for uint64_t type */
#include <siginfo.h>		/* signal handlers & SA_SIGINFO */
#endif
#ifndef CRAY
#include <sys/uio.h>		/* for struct iovec (readv) */
#include <sys/mman.h>		/* for mmap(2) */
#include <sys/ipc.h>		/* for i/o buffer in shared memory */
#include <sys/shm.h>		/* for i/o buffer in shared memory */
#endif
#include <sys/wait.h>
#ifdef CRAY
#include <sys/listio.h>
#include <sys/panic.h>
#endif
#include <sys/time.h>		/* for delays */
#include "doio.h"
#include "write_log.h"
#include "random_range.h"
#include "string_to_tokens.h"
#include "pattern.h"
#define	NMEMALLOC	32
#define	MEM_DATA	1	/* data space                           */
#define	MEM_SHMEM	2	/* System V shared memory               */
#define	MEM_T3ESHMEM	3	/* T3E Shared Memory                    */
#define	MEM_MMAP	4	/* mmap(2)                              */
#define	MEMF_PRIVATE	0001
#define	MEMF_AUTORESRV	0002
#define	MEMF_LOCAL	0004
#define	MEMF_SHARED	0010
#define	MEMF_FIXADDR	0100
#define	MEMF_ADDR	0200
#define	MEMF_AUTOGROW	0400
#define	MEMF_FILE	01000	/* regular file -- unlink on close      */
#define	MEMF_MPIN	010000	/* use mpin(2) to lock pages in memory */
#ifdef sgi
#endif
#ifndef CRAY
#endif
#ifdef CRAY
#endif
#ifdef sgi
#endif
#define	SY_WRITE		00001
#define	SY_ASYNC		00010
#define	SY_IOSW			00020
#define	SY_SDS			00100
#ifndef O_SSD
#define O_SSD 0			/* so code compiles on a CRAY2 */
#endif
#ifdef sgi
#define UINT64_T uint64_t
#else
#define UINT64_T unsigned long
#endif
#ifndef O_PARALLEL
#define O_PARALLEL 0		/* so O_PARALLEL may be used in expressions */
#endif
#define PPID_CHECK_INTERVAL 5	/* check ppid every <-- iterations */
#define	MAX_AIO		256	/* maximum number of async I/O ops */
#ifdef _CRAYMPP
#define	MPP_BUMP	16	/* page un-alignment for MPP */
#else
#define	MPP_BUMP	0
#endif
#define	SYSERR strerror(errno)
#define OPTS	"aC:d:ehm:n:kr:w:vU:V:M:N:"
#define DEF_RELEASE_INTERVAL	0
#define SKIP_REQ	-2	/* skip I/O request */
#define FD_ALLOC_INCR	32	/* allocate this many fd_map structs    */
#ifdef CRAY
#endif /* CRAY */
#ifdef CRAY
#endif /* CRAY */
#if defined(_CRAY1) || defined(CRAY)
#endif /* defined(_CRAY1) || defined(CRAY) */
#ifdef CRAY
#endif /* CRAY */
#ifdef sgi
#endif /* sgi */
#ifndef CRAY
#endif /* !CRAY */
#ifdef sgi
#endif /* sgi */
#ifndef CRAY
#endif /* !CRAY */
#ifdef sgi
#endif /* sgi */
#ifndef CRAY
#endif /* !CRAY */
#if defined(_CRAY1) || defined(CRAY)
#endif /* defined(_CRAY1) || defined(CRAY) */
#ifdef sgi
#else /* !sgi */
#ifndef CRAY
#endif /* !CRAY */
#endif /* sgi */
#ifdef sgi
#endif /* sgi */
#ifndef __linux__
#endif /* !__linux__ */
#ifndef CRAY
#endif /* !CRAY */
#define U_CORRUPTION	0001	/* upanic on data corruption    */
#define U_IOSW	    	0002	/* upanic on bad iosw           */
#define U_RVAL	    	0004	/* upanic on bad rval           */
#define U_ALL	    	(U_CORRUPTION | U_IOSW | U_RVAL)
#define	C_DEFAULT	1
#define	DELAY_SELECT	1
#define	DELAY_SLEEP	2
#define	DELAY_SGINAP	3
#define	DELAY_ALARM	4
#define	DELAY_ITIMER	5	/* POSIX timer                          */
#ifdef sgi
#endif
#ifdef CRAY
#elif defined(linux)
#else
#endif
#if _CRAYMPP
#endif
#ifdef SIGRECOVERY
#endif
#ifdef SIGCKPT
#endif
#ifdef SIGRESTART
#endif
#ifndef CRAY
#endif
#ifdef sgi
#else
#ifndef CRAY
#endif
#endif
#ifndef CRAY
#endif
#ifdef SIGRECOVERY
#endif
#ifdef SIGERR			/* cray only signals */
#endif
#ifdef NOTDEF
#else
#endif
#ifdef _CRAY1
#endif /* _CRAY1 */
#ifdef CRAY
#endif
#ifdef sgi
#ifdef F_FSYNC
#endif
#endif /* sgi */
#ifndef CRAY
#endif
#ifdef sgi
#endif
#ifdef CRAY
#ifdef O_SSD
#endif
#endif
#ifdef sgi
#endif
#ifdef CRAY
#endif /* CRAY */
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifndef wtob
#define wtob(x)	(x * sizeof(UINT64_T))
#endif
#ifdef CRAY
#else
#ifdef sgi
#else
#endif /* !CRAY && sgi */
#endif /* CRAY */
#ifdef CRAY
#endif /* CRAY */
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifdef CRAY
#ifndef _CRAYMPP
#else
#endif /* !CRAYMPP */
#else /* CRAY */
#ifdef sgi
#else /* sgi */
#endif /* sgi */
#endif /* CRAY */
#ifdef sgi
#else
#endif
#ifdef CRAY
#endif /* CRAY */
#ifdef CRAY
#else
#endif
#ifdef CRAY
#endif /* CRAY */
#ifdef CRAY
#else
#endif
#ifdef _CRAY1
#else
#ifdef CRAY
#endif /* CRAY */
#endif /* _CRAY1 */
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifdef CRAY
#endif /* CRAY */
#ifdef sgi
#endif /* sgi */
#ifndef CRAY
#endif /* !CRAY */
#ifdef sgi
#endif /* sgi */
#ifndef CRAY
#endif /* !CRAY */
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifndef CRAY
#endif
#if defined(CRAY) || defined(sgi)
#endif
#ifdef sgi
#endif
#ifdef CRAY
#else
#ifdef sgi
#else
#endif /* sgi */
#endif /* CRAY */
#ifdef CRAY
#ifndef _CRAYMPP
#else
#endif /* _CRAYMPP */
#else /* CRAY */
#endif /* CRAY */
#ifdef _CRAYMPP
#endif
#ifdef sgi
#endif
#ifndef __linux__
#endif
#ifdef CRAY
#endif /* CRAY */
#ifdef sgi
#endif /* sgi */
#ifdef sgi
#ifdef F_FSYNC
#endif
#endif /* sgi */
#ifndef CRAY
#endif /* !CRAY */
#ifdef sgi
#endif
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifdef sgi
#else
#endif
#ifndef CRAY
#ifdef __linux__
#endif
#ifdef __linux__
#endif
#ifdef sgi
#endif
#ifdef sgi
#endif
#ifdef sgi
#else
#endif
#ifdef sgi
#endif
#ifdef sgi
#endif
#ifdef sgi
#endif
#ifdef sgi
#endif
#ifdef sgi
#endif
#ifdef sgi
#endif
#ifdef sgi
#endif
#ifdef sgi
#else
#endif
#ifdef DEBUG
#endif
#ifdef sgi
#endif
#else /* CRAY */
#ifdef NOTDEF
#else
#ifdef _CRAYT3E
#endif /* _CRAYT3E */
#endif /* NOTDEF */
#endif /* CRAY */
#ifdef _CRAY1
#else
#ifdef CRAY
#endif
#endif /* _CRAY1 */
int alloc_fd(char *file, int oflags)
{
	struct fd_cache *fdc;
	struct fd_cache *alloc_fdcache(char *file, int oflags);

	fdc = alloc_fdcache(file, oflags);
	if (fdc != NULL)
		return (fdc->c_fd);
	else
		return (-1);
}
#ifdef sgi
#endif
#ifndef CRAY
#endif
#ifdef CRAY
#else
#endif
#ifdef CRAY
#else
#endif
#ifdef sgi
#endif /* sgi */
#ifndef CRAY
#endif
#ifdef sgi
#else
#ifndef CRAY
#endif /* !CRAY */
#endif /* sgi */
#ifdef sgi
#endif
#ifdef CRAY
#endif
#ifndef __linux__
#ifdef RECALL_SIZEOF
#endif
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifdef CRAY
#ifdef RECALL_SIZEOF
#endif
#endif /* CRAY */
#ifdef sgi
#if 0
#endif
#endif
#endif /* !linux */
#ifdef CRAY
#endif
#ifdef sgi
#else
#endif
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifndef CRAY
#else
#endif
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifndef CRAY
void parse_memalloc(char *arg)
{
	char *allocargs[NMEMALLOC];
	int nalloc;
	struct memalloc *M;

	if (Nmemalloc >= NMEMALLOC) {
		doio_fprintf(stderr, "Error - too many memory types (%d).\n",
			     Nmemalloc);
		return;
	}

	M = &Memalloc[Nmemalloc];

	nalloc = string_to_tokens(arg, allocargs, 32, ":");
	if (!strcmp(allocargs[0], "data")) {
		M->memtype = MEM_DATA;
		M->flags = 0;
		M->name = NULL;
		M->space = NULL;
		Nmemalloc++;
		if (nalloc >= 2) {
			if (strchr(allocargs[1], 'p'))
				M->flags |= MEMF_MPIN;
		}
	} else if (!strcmp(allocargs[0], "mmap")) {
		/* mmap:flags:filename[:size] */
		M->memtype = MEM_MMAP;
		M->flags = 0;
		M->space = NULL;
		if (nalloc >= 1) {
			if (strchr(allocargs[1], 'p'))
				M->flags |= MEMF_PRIVATE;
			if (strchr(allocargs[1], 'a'))
				M->flags |= MEMF_AUTORESRV;
			if (strchr(allocargs[1], 'l'))
				M->flags |= MEMF_LOCAL;
			if (strchr(allocargs[1], 's'))
				M->flags |= MEMF_SHARED;

			if (strchr(allocargs[1], 'f'))
				M->flags |= MEMF_FIXADDR;
			if (strchr(allocargs[1], 'A'))
				M->flags |= MEMF_ADDR;
			if (strchr(allocargs[1], 'G'))
				M->flags |= MEMF_AUTOGROW;

			if (strchr(allocargs[1], 'U'))
				M->flags |= MEMF_FILE;
		} else {
			M->flags |= MEMF_PRIVATE;
		}

		if (nalloc > 2) {
			if (!strcmp(allocargs[2], "devzero")) {
				M->name = "/dev/zero";
				if (M->flags &
				    ((MEMF_PRIVATE | MEMF_LOCAL) == 0))
					M->flags |= MEMF_PRIVATE;
			} else {
				M->name = allocargs[2];
			}
		} else {
			M->name = "/dev/zero";
			if (M->flags & ((MEMF_PRIVATE | MEMF_LOCAL) == 0))
				M->flags |= MEMF_PRIVATE;
		}
		Nmemalloc++;

	} else if (!strcmp(allocargs[0], "shmem")) {
		/* shmem:shmid:size */
		M->memtype = MEM_SHMEM;
		M->flags = 0;
		M->space = NULL;
		if (nalloc >= 2) {
			M->name = allocargs[1];
		} else {
			M->name = NULL;
		}
		if (nalloc >= 3) {
			sscanf(allocargs[2], "%i", &M->nblks);
		} else {
			M->nblks = 0;
		}
		if (nalloc >= 4) {
			if (strchr(allocargs[3], 'p'))
				M->flags |= MEMF_MPIN;
		}

		Nmemalloc++;
	} else {
		doio_fprintf(stderr, "Error - unknown memory type '%s'.\n",
			     allocargs[0]);
		exit(1);
	}
}
void dump_memalloc(void)
{
	int ma;
	char *mt;

	if (Nmemalloc == 0) {
		printf("No memory allocation strategies devined\n");
		return;
	}

	for (ma = 0; ma < Nmemalloc; ma++) {
		switch (Memalloc[ma].memtype) {
		case MEM_DATA:
			mt = "data";
			break;
		case MEM_SHMEM:
			mt = "shmem";
			break;
		case MEM_MMAP:
			mt = "mmap";
			break;
		default:
			mt = "unknown";
			break;
		}
		printf("mstrat[%d] = %d %s\n", ma, Memalloc[ma].memtype, mt);
		printf("\tflags=%#o name='%s' nblks=%d\n",
		       Memalloc[ma].flags,
		       Memalloc[ma].name, Memalloc[ma].nblks);
	}
}
#endif /* !CRAY */
#ifdef sgi
#endif
#ifndef CRAY
#ifdef sgi
#else
#endif /* sgi */
#ifdef sgi
#else
#endif
#endif /* !CRAY */
#ifdef sgi
#endif
#ifdef CRAY
#endif
