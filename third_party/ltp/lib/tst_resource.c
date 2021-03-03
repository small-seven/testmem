#include <pthread.h>
#include "test.h"
#include "old_resource.h"
#include "ltp_priv.h"
#ifndef PATH_MAX
#ifdef MAXPATHLEN
#define PATH_MAX	MAXPATHLEN
#else
#define PATH_MAX	1024
#endif
#endif
