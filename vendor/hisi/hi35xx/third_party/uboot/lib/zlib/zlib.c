#include <common.h>
#ifdef CONFIG_GZIP_COMPRESSED
#define NO_DUMMY_DECL
#include "deflate.c"
#include "trees.c"
#endif
#include "zutil.h"
#include "inftrees.h"
#include "inflate.h"
#include "inffast.h"
#include "inffixed.h"
#include "inffast.c"
#include "inftrees.c"
#include "inflate.c"
#include "zutil.c"
#include "adler32.c"
