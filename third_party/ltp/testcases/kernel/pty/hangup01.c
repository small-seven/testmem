#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/poll.h>
#include "test.h"
#include "safe_macros.h"
#define MASTERCLONE "/dev/ptmx"
#define MESSAGE1 "I love Linux!"
#define MESSAGE2 "Use the LTP for all your Linux testing needs."
#define MESSAGE3 "For the latest version of the LTP tests, visit http://ltp.sourceforge.net"
#define NUMMESSAGES 3
#define BUFSZ 4096
#ifdef DEBUG
#endif
