#define _GNU_SOURCE
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "tst_test.h"
#include "lapi/socket.h"
#include "tst_safe_macros.h"
#include "sendmmsg_var.h"
#define BUFSIZE 16
#define VLEN 2
