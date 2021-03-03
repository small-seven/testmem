#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdint.h>
#include <setjmp.h>
#include "posixtest.h"
#define	NUMSIGNALS	(sizeof(sigs) / sizeof(sigs[0]))
