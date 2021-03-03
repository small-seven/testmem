#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#define	TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#include "libnewipc.h"
#define BUFSIZE 1024
