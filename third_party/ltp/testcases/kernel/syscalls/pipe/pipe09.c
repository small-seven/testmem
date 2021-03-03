#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include "test.h"
#include "safe_macros.h"
#define	PIPEWRTCNT	100	/* must be an even number */
