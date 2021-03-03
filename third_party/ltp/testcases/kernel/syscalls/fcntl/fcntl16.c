#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include "test.h"
#include "safe_macros.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SKIPVAL 0x0f00
#define SKIP 0,0,0L,0L,0
#if (SKIPVAL == F_RDLCK) || (SKIPVAL == F_WRLCK)
#error invalid SKIP, must not be F_RDLCK or F_WRLCK
#endif
#define	IGNORED		0
#define	NOBLOCK		2	/* immediate success */
#define	WILLBLOCK	3	/* blocks, succeeds, parent unlocks records */
#define	TIME_OUT	10
typedef struct {
	struct flock parent_a;
	struct flock parent_b;
	struct flock child_a;
	struct flock child_b;
	struct flock parent_c;
	struct flock parent_d;
} testcase;
#define	FILEDATA	"tenbytes!"
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#endif
