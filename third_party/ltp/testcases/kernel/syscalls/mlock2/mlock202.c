#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <pwd.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#define PAGES 8
