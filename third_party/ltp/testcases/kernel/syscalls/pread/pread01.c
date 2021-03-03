#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <inttypes.h>
#include "test.h"
#include "safe_macros.h"
#define TEMPFILE	"pread_file"
#define K1              1024
#define K2              (K1 * 2)
#define K3              (K1 * 3)
#define K4              (K1 * 4)
#define NBUFS           4
