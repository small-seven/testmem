#include <stdio.h>
#include <pthread.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include "posixtest.h"
#define NAMESIZE 50
#define MSGSTR "0123456789"
#define BUFFER 40
#define MAXMSG 10
#define TIMEOUT 10		/* seconds mq_timedsend will block */
#define SIGNAL_DELAY_MS 50	/* delay in ms between 2 signals */
#define error_and_exit(en, msg) \
