#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <linux/net.h>
#include "tst_test.h"
#include "lapi/fcntl.h"
#include "lapi/syscalls.h"
#define PORT_NUM 33333
