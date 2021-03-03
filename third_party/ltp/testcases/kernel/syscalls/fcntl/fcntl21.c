#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <inttypes.h>
#include "test.h"
#define STRINGSIZE	27
#define STRING		"abcdefghijklmnopqrstuvwxyz\n"
#define STOP		0xFFF0
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
