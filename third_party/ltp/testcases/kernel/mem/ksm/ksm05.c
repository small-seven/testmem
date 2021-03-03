#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include "tst_test.h"
#include "mem.h"
#ifdef HAVE_DECL_MADV_MERGEABLE
#else
#endif
