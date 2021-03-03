#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "test.h"
#define F_RGETLK 10		/* kludge code */
#define F_RSETLK 11		/* kludge code */
#define STRINGSIZE	27
#define	STRING		"abcdefghijklmnopqrstuvwxyz\n"
#ifdef LINUX_FILE_REGION_LOCK
#else
#endif
