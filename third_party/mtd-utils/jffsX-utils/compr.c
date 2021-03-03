#include "compr.h"
#include <string.h>
#include <stdlib.h>
#include <linux/jffs2.h>
#define FAVOUR_LZO_PERCENT 80
#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define LIST_HEAD(name) \
#define list_entry(ptr, type, member) \
#define list_for_each_entry(pos, head, member)                          \
#define JFFS2_BUFFER_FILL 0x55
#define JFFS2_STAT_BUF_SIZE 16000
#ifdef CONFIG_JFFS2_ZLIB
#endif
#ifdef CONFIG_JFFS2_RTIME
#endif
#ifdef CONFIG_JFFS2_LZO
#endif
#ifdef CONFIG_JFFS2_RTIME
#endif
#ifdef CONFIG_JFFS2_ZLIB
#endif
#ifdef CONFIG_JFFS2_LZO
#endif
