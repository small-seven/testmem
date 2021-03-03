#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include "ipcshm.h"
#include "safe_macros.h"
#define FIRST	0
#define SECOND	1
#define N_ATTACH	4
#ifndef UCLINUX
#endif
#define NEWMODE	0066
#ifdef UCLINUX
#define PIPE_NAME	"shmctl01"
#endif
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
