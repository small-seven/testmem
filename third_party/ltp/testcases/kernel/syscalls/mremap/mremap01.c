#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "test.h"
#include "safe_macros.h"
#define TEMPFILE	"mremapfile"
