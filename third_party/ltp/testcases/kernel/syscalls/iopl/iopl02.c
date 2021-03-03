#if defined __i386__ || defined(__x86_64__)
#include <errno.h>
#include <unistd.h>
#include <sys/io.h>
#include <pwd.h>
#include "test.h"
#include "safe_macros.h"
#define INVALID_LEVEL 4		/* Invalid privilege level */
#define EXP_RET_VAL -1
#else /* __i386__ */
#include "test.h"
#include "safe_macros.h"
#endif /* __i386__ */
