#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <unistd.h>
#define K_1  1024
#define SHMBYTES    (SHMLBA - 1)
#define SHMALIGN(p) (((unsigned long)(p) + SHMBYTES) & ~SHMBYTES)
#include "test.h"
#ifdef __ia64__
#define INCREMENT 		8388608	/* 8Mb */
#elif defined (__mips__)  ||  defined (__hppa__) || defined (__sparc__)
#define INCREMENT		262144	/* 256Kb */
#elif defined __sh__ || defined (__arm__) || defined(__aarch64__)
#define INCREMENT 		16384	/* 16kb */
#else
#define INCREMENT 		SHMLBA
#endif
#ifdef __mips__
#elif  defined(__powerpc__) || defined(__powerpc64__)
#else
#endif
#if defined (__ia64__) || defined(__mips__) || defined(__hppa__) || defined(__arm__) || defined(__aarch64__)
#else
#endif
