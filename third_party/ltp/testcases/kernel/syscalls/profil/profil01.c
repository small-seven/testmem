#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/abisize.h"
#include "config.h"
#if HAVE_PROFIL
#define PROFIL_TIME 5
#define PROFIL_BUFLEN (32*1024)
#if defined(__s390__) && defined(TST_ABI32)
#else
#endif
#else /* systems without profil() */
#endif
