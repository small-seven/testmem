#include <signal.h>
#include <stdlib.h>
#include "config.h"
#include "tst_test.h"
#include "tst_safe_pthread.h"
#ifdef HAVE_STRUCT_SIGACTION_SA_SIGACTION
#include "rt_sigqueueinfo.h"
#define SIGNAL	SIGUSR1
#define DATA	777
#else
#endif /* HAVE_STRUCT_SIGACTION_SA_SIGACTION */
