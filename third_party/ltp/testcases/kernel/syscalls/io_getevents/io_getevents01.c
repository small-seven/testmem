#include <errno.h>
#include <string.h>
#include "config.h"
#include "test.h"
#ifdef HAVE_LIBAIO
#include <libaio.h>
#define EXP_RET (-EINVAL)
#else
#endif
