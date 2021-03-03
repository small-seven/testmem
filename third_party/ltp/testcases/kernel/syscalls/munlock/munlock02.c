#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pwd.h>
#include "test.h"
#define LEN	1024
#if !defined(UCLINUX)
#ifdef __ia64__
#endif
#else
#endif /* if !defined(UCLINUX) */
