#include <errno.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"
#define	KIDEXIT	42
#define LINE_SZ	20
#define FILENAME "childpid"
