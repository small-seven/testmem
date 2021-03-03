#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "tst_test.h"
#include "tst_safe_macros.h"
#define TESTFILE	"test_file"
