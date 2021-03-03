#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <errno.h>
#include "posixtest.h"
#define NAMESIZE 50
#define MSGSTR "0123456789"
#define BUFFER 40
#define MAXMSG 5
#define TIMEOUT 7
#define CHILDPASS 1
#define CHILDFAIL 0
#ifdef _POSIX_TIMERS
#else
#endif
