#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <pwd.h>
#include "test.h"
#include "safe_macros.h"
#if !defined(UCLINUX)
#else
#endif /* if !defined(UCLINUX) */
