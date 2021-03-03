#define _GNU_SOURCE 1
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "test.h"
#define FAILED 0
#define PASSED 1
#define MAXLOOPS	500	/* max pages for map children to write */
#define	MAPSIZE		(64*1024)	/* default mapsize set up by parent */
#ifdef roundup
#undef roundup
#endif
#define roundup(x, y)	((((x)+((y)-1))/(y))*(y))
#define min(x, y)	(((x) < (y)) ? (x) : (y))
typedef unsigned char uchar_t;

char *usage = "-p nprocs [-t minutes -s mapsize -m -r -d]";

unsigned int initrand(void);
void finish(int sig);
void child_mapper(unsigned procno, unsigned nprocs);
int mapokay(uchar_t * expbuf);

int finished = 0;
int debug = 0;
int mapsize = MAPSIZE;
unsigned mappages;
int pagesize;
unsigned randloops = 0;
unsigned dosync = 0;
unsigned pattern = 0;
caddr_t mapaddr;

int main(int argc, char *argv[])
{
	char *progname;
	unsigned c;
	extern char *optarg;
	unsigned nprocs = 0;
	unsigned procno;
	pid_t *pidarray = NULL;
	pid_t pid;
	uchar_t *buf, *ptr;
	unsigned int seed;
	float alarmtime = 0;
	struct sigaction sa;
	unsigned i, j;
	uchar_t data;
	int no_prob = 0;
	time_t t;
	int wait_stat;

	progname = *argv;
	pagesize = sysconf(_SC_PAGE_SIZE);

	if (argc < 2) {
		(void)fprintf(stderr, "usage: %s %s\n", progname, usage);
		anyfail();
	}
