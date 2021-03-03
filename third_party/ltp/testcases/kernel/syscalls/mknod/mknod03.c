#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "test.h"
#include "safe_macros.h"
#define LTPUSER		"nobody"
#define MODE_RWX	S_IFIFO | S_IRWXU | S_IRWXG | S_IRWXO
#define MODE_SGID       S_IFIFO | S_ISGID | S_IRWXU | S_IRWXG | S_IRWXO
#define DIR_TEMP	"testdir_3"
#define TNODE		"tnode_%d"
