#define _GNU_SOURCE		/* for asprintf */
#include "config.h"
#ifdef UCLINUX
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "test.h"
#include "safe_macros.h"
#endif /* UCLINUX */
