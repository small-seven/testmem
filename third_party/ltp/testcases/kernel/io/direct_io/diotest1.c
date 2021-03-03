#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "diotest_routines.h"
#include "test.h"
#include "safe_macros.h"
#ifdef O_DIRECT
#define	BUFSIZE	8192
#define	NBLKS	20
#define	LEN	30
#define	TRUE 1
#else /* O_DIRECT */
#endif /* O_DIRECT */
