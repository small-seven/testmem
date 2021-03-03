#include "test.h"
#include <errno.h>
#include <signal.h>
typedef void (*sighandler_t) (int);

sighandler_t Tret;
int sigs[] = { _NSIG + 1, SIGKILL, SIGSTOP };
