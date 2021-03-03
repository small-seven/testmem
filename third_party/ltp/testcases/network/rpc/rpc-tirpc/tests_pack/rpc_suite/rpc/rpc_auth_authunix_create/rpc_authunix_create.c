#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <rpc/rpc.h>
#include <sys/socket.h>
#include <utmp.h>
#include <sys/time.h>
#include <netdb.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#define PROCNUM 1
#define VERSNUM 1
#ifndef NGROUPS_MAX
#define NGROUPS_MAX 16
#endif
