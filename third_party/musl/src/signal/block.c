#include "pthread_impl.h"
#include "syscall.h"
#include <signal.h>
#if ULONG_MAX == 0xffffffff && _NSIG == 129
#elif ULONG_MAX == 0xffffffff
#else
#endif
#if ULONG_MAX == 0xffffffff
#if _NSIG == 65
#else
#endif
#else
#if _NSIG == 65
#else
#endif
#endif
