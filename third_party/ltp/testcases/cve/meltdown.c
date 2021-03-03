#include "config.h"
#include "tst_test.h"
#if defined(__x86_64__) || defined(__i386__)
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <ucontext.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/utsname.h>
#include <emmintrin.h>
#include "libtsc.h"
#define TARGET_OFFSET	9
#define TARGET_SIZE	(1 << TARGET_OFFSET)
#define BITS_BY_READ	2
#ifdef __x86_64__
#else /* defined(__x86_64__) */
#endif
#ifdef __i386__
# define REG_RIP	REG_EIP
#endif
#define CYCLES 10000
#ifdef DEBUG
#endif
#define ESTIMATE_CYCLES	1000000
#define READ_SIZE 32
#else /* #if defined(__x86_64__) || defined(__i386__) */
#endif /* #else #if defined(__x86_64__) || defined(__i386__) */
