#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "test.h"
#include "usctest.h"
#include "safe_macros.h"
#define MAX_SANE_HARD_LINKS	65535
