#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "test.h"
#include "safe_macros.h"
#define TEMPFILE	"mmapfile"
#ifndef UCLINUX
#else
#endif /* ifndef UCLINUX */
#ifdef UCLINUX
#else
#endif
