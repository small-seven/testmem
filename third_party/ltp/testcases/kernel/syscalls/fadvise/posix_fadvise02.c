#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#define WRONG_FD       42	/* The number has no meaning.
