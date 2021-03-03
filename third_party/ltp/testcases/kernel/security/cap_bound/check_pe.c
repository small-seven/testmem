#include <errno.h>
#include "config.h"
#if HAVE_SYS_CAPABILITY_H
#include <linux/types.h>
#include <sys/capability.h>
#endif
#include <sys/prctl.h>
#include "test.h"
#ifdef HAVE_SYS_CAPABILITY_H
#ifdef HAVE_LIBCAP
#else /* libcap */
#endif
#else /* capability_h */
#endif
