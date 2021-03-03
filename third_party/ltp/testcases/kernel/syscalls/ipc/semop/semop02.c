#define _GNU_SOURCE
#include <pwd.h>
#include "test.h"
#include "safe_macros.h"
#include "ipcsem.h"
#define NSOPS	5		/* a resonable number of operations */
#define	BIGOPS	1024		/* a value that is too large for the number */
