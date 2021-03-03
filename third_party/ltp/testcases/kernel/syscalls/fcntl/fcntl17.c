#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <inttypes.h>
#include "test.h"
#define STRINGSIZE	27
#define STRING		"abcdefghijklmnopqrstuvwxyz\n"
#define STOP		0xFFF0
#define TIME_OUT	10
void parent_free(int arg)
{
	if (write(parent_pipe[1], &arg, sizeof(arg)) != sizeof(arg)) {
		tst_resm(TFAIL, "couldn't send message to parent");
		exit(1);
	}
}
void child_free(int fd, int arg)
{
	if (write(fd, &arg, sizeof(arg)) != sizeof(arg)) {
		tst_resm(TFAIL, "couldn't send message to child");
		exit(1);
	}
}
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#else
#endif
