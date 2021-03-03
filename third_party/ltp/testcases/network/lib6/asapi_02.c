#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <netinet/icmp6.h>
#include "test.h"
#include "safe_macros.h"
#define FTCOUNT	ARRAY_SIZE(ftab)
