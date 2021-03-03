#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include "tlibio.h"
#include "test.h"
#include "safe_macros.h"
#include "lapi/semun.h"
#define SAFE_FREE(p) { if (p) { free(p); (p)=NULL; } }
#if defined(__linux__)
#define NBPW sizeof(int)
#endif
#define OCTAL	'o'
#define HEX	'x'
#define DECIMAL	'd'
#define ASCII	'a'
#define NO_OUT	'n'
#define PIPE_NAMED	"named pipe,"
#define PIPE_UNNAMED	"sys pipe,"
#define BLOCKING_IO	"blking,"
#define NON_BLOCKING_IO	"non-blking,"
#define UNNAMED_IO	""
#define MAX_ERRS 16
#define MAX_EMPTY 256
#if DEBUG
#endif
