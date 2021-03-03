#define _XOPEN_SOURCE 500
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/file.h>
#include "test.h"
#define PREAD_TEMPDIR	"test"
#define K1              2048
#define NBUFS           1
