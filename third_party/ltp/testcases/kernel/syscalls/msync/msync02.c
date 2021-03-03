#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "test.h"
#define TEMPFILE	"msync_file"
#define BUF_SIZE	256
