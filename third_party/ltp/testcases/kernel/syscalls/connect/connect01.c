#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/signal.h>
#include <sys/un.h>
#include <netinet/in.h>
#include "test.h"
#include "safe_macros.h"
#ifndef UCLINUX
#endif
#ifdef UCLINUX
#endif
#include "lapi/syscalls.h"
#define connect(sockfd, addr, addrlen) sys_connect(sockfd, addr, addrlen)
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
