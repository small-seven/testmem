#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/mman.h>
#include "test.h"
#include "safe_macros.h"
#include <sys/resource.h>
#if !defined(UCLINUX)
#else
#endif /* if !defined(UCLINUX) */
