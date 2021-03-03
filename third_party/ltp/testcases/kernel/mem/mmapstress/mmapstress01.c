#define _GNU_SOURCE 1
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <limits.h>
#include "test.h"
#define FAILED 0
#define PASSED 1
#define MAXLOOPS	500	/* max pages for map children to write */
#define	FILESIZE	4096	/* initial filesize set up by parent */
#ifdef roundup
#undef roundup
#endif
#define roundup(x, y)	((((x)+((y)-1))/(y))*(y))
#define min(x, y)	(((x) < (y)) ? (x) : (y))
typedef unsigned char uchar_t;
#define SIZE_MAX UINT_MAX

unsigned int initrand(void);
void finish(int sig);
void child_mapper(char *file, unsigned procno, unsigned nprocs);
int fileokay(char *file, uchar_t * expbuf);
int finished = 0;
int leavefile = 0;

int debug = 0;
#ifdef LARGE_FILE
off64_t filesize = FILESIZE;
off64_t sparseoffset = 0;
#else /* LARGE_FILE */
off_t filesize = FILESIZE;
off_t sparseoffset = 0;
#endif /* LARGE_FILE */
unsigned randloops = 0;
unsigned dosync = 0;
unsigned do_offset = 0;
unsigned pattern = 0;

int main(int argc, char *argv[])
{
	char *progname;
	int fd;
	int c;
	extern char *optarg;
	unsigned nprocs = 0;
	unsigned procno;
	pid_t *pidarray = NULL;
	pid_t pid;
	uchar_t *buf = NULL;
	unsigned int seed;
	int pagesize = sysconf(_SC_PAGE_SIZE);
	float alarmtime = 0;
	struct sigaction sa;
	unsigned i;
	int write_cnt;
	uchar_t data;
	int no_prob = 0;
	int wait_stat;
	time_t t;
#ifdef LARGE_FILE
	off64_t bytes_left;
#else /* LARGE_FILE */
	off_t bytes_left;
#endif /* LARGE_FILE */
	const char *filename = "mmapstress01.out";

	progname = *argv;
	tst_tmpdir();
	if (argc < 2) {
		tst_brkm(TBROK, NULL, "usage: %s %s\n", progname, usage);
	}
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
#ifdef LARGE_FILE
#else /* LARGE_FILE */
#endif /* LARGE_FILE */
