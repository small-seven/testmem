#include <sys/resource.h>
#include <errno.h>
#include <unsupported_api.h>
#include "syscall.h"
#include "libc.h"
#define MIN(a, b) ((a)<(b) ? (a) : (b))
#define FIX(x) do{ if ((x)>=SYSCALL_RLIM_INFINITY) (x)=RLIM_INFINITY; }while(0)
