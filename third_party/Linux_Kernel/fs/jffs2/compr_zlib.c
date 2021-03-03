#include <linux/kernel.h>
#include <zlib.h>
#include <linux/zutil.h>
#include <linux/semaphore.h>
#include "nodelist.h"
#include "compr.h"
#define STREAM_END_SPACE 12
#define alloc_workspaces() (0)
#define free_workspaces() do { } while(0)
#ifdef JFFS2_ZLIB_DISABLED
#else
#endif
