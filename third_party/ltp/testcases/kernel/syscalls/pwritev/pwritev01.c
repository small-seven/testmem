#define _GNU_SOURCE
#include <string.h>
#include <sys/uio.h>
#include "tst_test.h"
#include "pwritev.h"
#include "tst_safe_prw.h"
#define	CHUNK		64
