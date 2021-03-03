#include <sys/param.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/utsname.h>
#include <errno.h>
#include <err.h>
#include <limits.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "splitstr.h"
#include "zoolib.h"
#include "tst_res_flags.h"
#define ResultFmt	"%-50s %-10.10s"
#define Dbuffile	0x000400	/* buffer file use */
#define	Dsetup		0x000200	/* one-time set-up */
#define	Dshutdown	0x000100	/* killed by signal */
#define	Dexit		0x000020	/* exit status */
#define	Drunning	0x000010	/* current pids running */
#define	Dstartup	0x000004	/* started command */
#define	Dstart		0x000002	/* started command */
#define Dwait		0x000001	/* wait interrupted */
#define WRITE_OR_DIE(fd, buf, buflen) do {				\
