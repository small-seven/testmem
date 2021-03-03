#define _XOPEN_SOURCE 500
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "test.h"
#include "safe_macros.h"
#define TEMPFILE	"pread_file"
#define K1              1024
#define NBUFS           4
