#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <sys/wait.h>
#include "ipcsem.h"
#include "safe_macros.h"
#define INCVAL 2
#define NEWMODE	066
#define NCHILD	5
#define SEM2	2
#define SEM4	4
#define ONE	1
#ifdef _XLC_COMPILER
#define SEMUN_CAST
#else
#define SEMUN_CAST (union semun)
#endif
#ifdef UCLINUX
#define PIPE_NAME	"semctl01"
#endif
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
