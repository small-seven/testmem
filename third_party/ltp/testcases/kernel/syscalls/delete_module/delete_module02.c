#include <errno.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#define BASEMODNAME	"dummy"
#define LONGMODNAMECHAR	'm'
#define MODULE_NAME_LEN	(64 - sizeof(unsigned long))
