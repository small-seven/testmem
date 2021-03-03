#include <signal.h>
#include <string.h>
#include "locale_impl.h"
#if (SIGHUP == 1) && (SIGINT == 2) && (SIGQUIT == 3) && (SIGILL == 4) \
#define sigmap(x) x
#else
#define sigmap(x) ((x) >= sizeof map ? (x) : map[(x)])
#endif
#if _NSIG > 65
#endif
