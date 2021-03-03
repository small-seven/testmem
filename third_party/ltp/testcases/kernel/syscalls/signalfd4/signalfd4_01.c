#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include "test.h"
#include "lapi/fcntl.h"
#include "lapi/syscalls.h"
#include "ltp_signal.h"
#define SFD_CLOEXEC O_CLOEXEC
