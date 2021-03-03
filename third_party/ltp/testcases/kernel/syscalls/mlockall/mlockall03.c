#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <ctype.h>
#include <sys/mman.h>
#include "test.h"
#include "safe_macros.h"
#include <sys/resource.h>
#include <sys/utsname.h>
#if !defined(UCLINUX)
#else
#endif /* if !defined(UCLINUX) */
