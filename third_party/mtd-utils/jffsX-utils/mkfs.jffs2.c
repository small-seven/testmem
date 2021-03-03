#define PROGRAM_NAME "mkfs.jffs2"
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <libgen.h>
#include <ctype.h>
#include <time.h>
#include <getopt.h>
#ifndef WITHOUT_XATTR
#include <sys/xattr.h>
#include <sys/acl.h>
#endif
#include <byteswap.h>
#include <crc32.h>
#include <inttypes.h>
#include <limits.h>
#include "rbtree.h"
#include "common.h"
#undef basename
#define mkfs_debug_msg(a...)	{ }
#define PAD(x) (((x)+3)&~3)
#ifdef __GNUC__
#if __STDC_VERSION__ >= 199901L
#define SCANF_PREFIX "m"
#else
#define SCANF_PREFIX "a"
#endif
#define SCANF_STRING(s) (&s)
#define GETCWD_SIZE 0
#else
#define SCANF_PREFIX "511"
#define SCANF_STRING(s) (s = xmalloc(512))
#define GETCWD_SIZE -1
#endif
#include "mtd/jffs2-user.h"
#define JFFS2_MAX_FILE_SIZE 0xFFFFFFFF
#ifndef JFFS2_MAX_SYMLINK_LEN
#define JFFS2_MAX_SYMLINK_LEN 254
#endif
#include "compr.h"
#ifndef WITHOUT_XATTR
typedef struct xattr_entry {
	struct xattr_entry *next;
	uint32_t xid;
	int xprefix;
	char *xname;
	char *xvalue;
	int name_len;
	int value_len;
} xattr_entry_t;
#define XATTR_BUFFER_SIZE		(64 * 1024)	/* 64KB */
#define XATTRENTRY_HASHSIZE	57
#else /* WITHOUT_XATTR */
#define write_xattr_entry(x)
#endif
#ifndef WITHOUT_XATTR
#endif
#ifndef WITHOUT_XATTR
#endif
#ifndef WITHOUT_XATTR
#endif
