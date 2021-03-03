#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/poll.h>
#include "tst_test.h"
#define BUF_SIZE	512
