#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include "test.h"
#include "move_pages_support.h"
#define SHARED_PAGE 0
#define N_SHARED_PAGES 1
#define UNSHARED_PAGE 1
#define N_UNSHARED_PAGES 1
#define N_TEST_PAGES (N_SHARED_PAGES + N_UNSHARED_PAGES)
#define N_TEST_NODES 2
#ifdef HAVE_NUMA_V2
#else
#endif
