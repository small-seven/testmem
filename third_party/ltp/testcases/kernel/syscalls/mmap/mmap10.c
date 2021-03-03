#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "test.h"
#include "config.h"
#define SIZE (5*1024*1024)
#define PATH_KSM "/sys/kernel/mm/ksm/"
#ifdef HAVE_DECL_MADV_MERGEABLE
#else
#endif
#ifdef HAVE_DECL_MADV_MERGEABLE
#endif
