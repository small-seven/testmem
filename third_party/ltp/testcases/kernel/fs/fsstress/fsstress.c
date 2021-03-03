#include "config.h"
#include "global.h"
#include <tst_common.h>
#ifdef HAVE_SYS_PRCTL_H
# include <sys/prctl.h>
#endif
#include <limits.h>
#define XFS_ERRTAG_MAX		17
typedef enum {
#ifndef NO_XFS
	OP_ALLOCSP,
	OP_ATTR_REMOVE,
	OP_ATTR_SET,
	OP_BULKSTAT,
	OP_BULKSTAT1,
#endif
	OP_CHOWN,
	OP_CREAT,
	OP_DREAD,
	OP_DWRITE,
	OP_FDATASYNC,
#ifndef NO_XFS
	OP_FREESP,
#endif
	OP_FSYNC,
	OP_GETDENTS,
	OP_LINK,
	OP_MKDIR,
	OP_MKNOD,
	OP_READ,
	OP_READLINK,
	OP_RENAME,
#ifndef NO_XFS
	OP_RESVSP,
#endif
	OP_RMDIR,
	OP_STAT,
	OP_SYMLINK,
	OP_SYNC,
	OP_TRUNCATE,
	OP_UNLINK,
#ifndef NO_XFS
	OP_UNRESVSP,
#endif
	OP_WRITE,
	OP_LAST
} opty_t;
typedef void (*opfnc_t) (int, long);

typedef struct opdesc {
	opty_t op;
	char *name;
	opfnc_t func;
	int freq;
	int iswrite;
	int isxfs;
} opdesc_t;
typedef struct fent {
	int id;
	int parent;
} fent_t;
typedef struct flist {
	int nfiles;
	int nslots;
	int tag;
	fent_t *fents;
} flist_t;
typedef struct pathname {
	int len;
	char *path;
} pathname_t;
#define	FT_DIR	0
#define	FT_DIRm	(1 << FT_DIR)
#define	FT_REG	1
#define	FT_REGm	(1 << FT_REG)
#define	FT_SYM	2
#define	FT_SYMm	(1 << FT_SYM)
#define	FT_DEV	3
#define	FT_DEVm	(1 << FT_DEV)
#define	FT_RTF	4
#define	FT_RTFm	(1 << FT_RTF)
#define	FT_nft	5
#define	FT_ANYm	((1 << FT_nft) - 1)
#define	FT_REGFILE	(FT_REGm | FT_RTFm)
#define	FT_NOTDIR	(FT_ANYm & ~FT_DIRm)
#define	FLIST_SLOT_INCR	16
#define	NDCACHE	64
#define	MAXFSIZE	((1ULL << 63) - 1ULL)
#define	MAXFSIZE32	((1ULL << 40) - 1ULL)
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#else
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifdef HAVE_SYS_PRCTL_H
#endif
#ifndef NO_XFS
#endif
#ifdef DEBUG
#endif
#ifndef NO_XFS
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#define WIDTH 80
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
#ifndef NO_XFS
#endif
