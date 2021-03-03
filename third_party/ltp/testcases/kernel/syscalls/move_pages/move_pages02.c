#include <sys/signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "test.h"
#include "move_pages_support.h"
#define TEST_PAGES 2
#define TEST_NODES 2
#ifdef HAVE_NUMA_V2
#else
#endif
