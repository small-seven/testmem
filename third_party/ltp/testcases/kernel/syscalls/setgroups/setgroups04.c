#include <sys/types.h>
#include <sys/param.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include "test.h"
#include "compat_16.h"
#if !defined(UCLINUX)
#else
#endif /* if !defined(UCLINUX) */
