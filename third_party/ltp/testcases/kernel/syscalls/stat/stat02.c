#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/signal.h>
#include <errno.h>
#include <stdlib.h>
#include "tst_test.h"
#define FNAME1	"stat02.1"
#define FNAME2	"stat02.2"
#define NUM_WRITES	(10)
#define BUFSIZE		(4096)
