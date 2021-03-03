#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#include <errno.h>
#include <pwd.h>
#include "test.h"
#include "safe_macros.h"
#include "move_pages_support.h"
#define TEST_PAGES 2
#define TEST_NODES 2
#ifdef HAVE_NUMA_V2
#else
#endif
