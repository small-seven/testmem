#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/fsuid.h>
#ifndef MS_REC
#define MS_REC		0x4000	/* 16384: Recursive loopback */
#endif
#ifndef MS_SHARED
#define MS_SHARED		1<<20	/* Shared */
#endif
#ifndef MS_PRIVATE
#define MS_PRIVATE		1<<18	/* Private */
#endif
#ifndef MS_SLAVE
#define MS_SLAVE		1<<19	/* Slave */
#endif
#ifndef MS_UNCLONE
#define MS_UNCLONE		1<<17	/* UNCLONE */
#endif
