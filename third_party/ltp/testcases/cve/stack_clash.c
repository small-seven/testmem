#include <sys/mman.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <alloca.h>
#include <signal.h>
#include <stdlib.h>
#include "tst_test.h"
#include "tst_safe_stdio.h"
#define SIGNAL_STACK_SIZE	(1UL<<20)
#define FRAME_SIZE		1024
#define REQ_STACK_SIZE		(1024 * 1024)
#define EXIT_TESTBROKE		TBROK
#define MAPPED_LEN page_size
#ifdef DEBUG
#endif
