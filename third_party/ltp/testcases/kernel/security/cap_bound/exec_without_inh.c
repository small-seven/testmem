#include <errno.h>
#include "config.h"
#if HAVE_SYS_CAPABILITY_H
#include <linux/types.h>
#include <sys/capability.h>
#endif
#include <sys/prctl.h>
#include "test.h"
#if HAVE_SYS_CAPABILITY_H
#if HAVE_DECL_PR_CAPBSET_DROP
#ifdef HAVE_LIBCAP
#else /* libcap */
#endif
#else /* HAVE_DECL_PR_CAPBSET_DROP */
#endif
#else /* capability_h */
#endif
