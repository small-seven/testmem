#define _GNU_SOURCE
#include <sys/resource.h>
#include "syscall.h"
#define FIX(x) do{ if ((x)>=SYSCALL_RLIM_INFINITY) (x)=RLIM_INFINITY; }while(0)
#undef prlimit64
