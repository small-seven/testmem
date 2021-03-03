#include "config.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_IO_H
#include <io.h>
#endif
#include <zlib.h>
#ifdef DEBUG
#define dbgprintf printf
#else
#define dbgprintf(...) do { if (0) printf(__VA_ARGS__); } while (0)
#endif
