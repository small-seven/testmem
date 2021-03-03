#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#ifdef CRAY
#include <sys/file.h>
#include <sys/iosw.h>
#include <sys/listio.h>
#endif
#ifdef sgi
#include <sys/statvfs.h>
#include <sys/fs/xfs_itable.h>
#endif
#ifdef CRAY
#include "libkern.h"
#endif
#include "doio.h"
#include "bytes_by_prefix.h"
#include "string_to_tokens.h"
#include "open_flags.h"
#include "random_range.h"
#ifndef PATH_MAX
#define	PATH_MAX 512		/* ??? */
#endif
#ifndef BSIZE
#ifdef linux
#define BSIZE DEV_BSIZE
#else
#define BSIZE 512
#endif
#endif
#define RAW_IO(_flags_)	((_flags_) & (O_RAW | O_SSD))
#ifndef __linux__
#endif
#define SYSERR	strerror(errno)
#define OPTS	"a:dhf:i:L:m:op:qr:s:t:T:O:N:"
#ifndef linux
#else
#endif /* !linux */
#ifdef CRAY
#if _UMK || RELEASE_LEVEL >= 8000
#endif
#ifdef RECALL_SIZEOF
#endif
#endif /* CRAY */
#ifdef sgi
#endif
#define M_RANDOM    	1
#define M_SEQUENTIAL	2
#define M_REVERSE   	3
#define	SY_ASYNC	00001
#define	SY_WRITE	00002
#define	SY_SDS		00010
#define	SY_LISTIO	00020
#define	SY_NENT		00100	/* multi entry vs multi stride >>> */
#ifdef CRAY
#ifndef _CRAYMPP
#endif
#endif
#ifdef sgi
#if 0
#endif
#endif /* SGI */
#ifndef CRAY
#endif
#define	FLG_RAW		00001
#ifdef CRAY
#ifdef O_SSD
#endif
#ifdef O_LDRAW
#endif
#ifdef O_PARALLEL
#endif
#endif /* CRAY */
#ifdef sgi
#endif
#ifdef CRAY
#else
#endif
#ifdef CRAY
#endif
#ifdef CRAY
#endif
#if CRAY
#endif
#ifdef CRAY
#endif
#ifdef CRAY
#endif
#ifdef sgi
#endif
#if _CRAY2
#endif
#ifdef CRAY
#endif
#ifdef linux
#endif
#ifdef sgi
#endif /* SGI */
#ifdef CRAY
#else
#ifdef sgi
#else
#endif /* sgi */
#endif /* CRAY */
#ifdef sgi
#endif
#ifdef sgi
#ifdef DEBUG
#endif
#endif /* sgi */
#ifdef sgi
#endif /* sgi */
#ifndef linux
#endif
#ifdef linux
#else
#endif
#ifdef O_SSD
#endif
#ifdef linux
#else
#endif
#ifdef CRAY
#endif
#ifdef linux
#endif
#ifdef sgi
#endif
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifndef CRAY
#endif
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifndef linux
#ifdef CRAY
#if _UMK || RELEASE_LEVEL >= 8000
#else
#endif
#else
#endif
#else /* !linux */
#endif /* !linux */
#ifdef CRAY
#else
#ifdef sgi
#else
#endif /* sgi */
#endif /* CRAY */
#ifndef linux
#else
#endif /* !linux */
#ifdef CRAY
#endif
#ifdef sgi
#endif
#ifdef linux
#endif
#ifdef sgi
#endif
#ifdef CRAY
#endif
#ifdef linux
#endif
