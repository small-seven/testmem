#include <errno.h>
#include <sys/statvfs.h>
#include <sys/mman.h>
#include "test.h"
#include "safe_macros.h"
#define TEST_SYMLINK	"statvfs_symlink"
#define TEST_FILE	"statvfs_file"
