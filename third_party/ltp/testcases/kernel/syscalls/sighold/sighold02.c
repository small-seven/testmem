#define _XOPEN_SOURCE 500
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/signal.h"
#ifndef NSIG
# define NSIG _NSIG
#endif
#ifndef NUMSIGS
# define NUMSIGS NSIG
#endif
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
