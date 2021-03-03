#define _GNU_SOURCE
#define SYSCALL_NO_TLS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <elf.h>
#include <sys/mman.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <link.h>
#include <setjmp.h>
#include <pthread.h>
#include <ctype.h>
#include <dlfcn.h>
#include <semaphore.h>
#include <sys/membarrier.h>
#include "pthread_impl.h"
#include "libc.h"
#include "dynlink.h"
#include "malloc_impl.h"
#define MAXP2(a,b) (-(-(a)&-(b)))
#define ALIGN(x,y) ((x)+(y)-1 & -(y))
#define container_of(p,t,m) ((t*)((char *)(p)-offsetof(t,m)))
#define countof(a) ((sizeof (a))/(sizeof (a)[0]))
#if DL_FDPIC
#else
#endif
#if DL_FDPIC
#else
#endif
typedef void (*stage3_func)(size_t *, size_t *);

static struct builtin_tls {
	char c;
	struct pthread pt;
	void *space[16];
} builtin_tls[1];
#define MIN_TLS_ALIGN offsetof(struct builtin_tls, pt)
#define ADDEND_LIMIT 4096
#define strcmp(l,r) dl_strcmp(l,r)
#if DL_FDPIC
#define fpaddr(p, v) fdbarrier((&(struct funcdesc){ \
#else
#define laddr(p, v) (void *)((p)->base + (v))
#define laddr_pg(p, v) laddr(p, v)
#define fpaddr(p, v) ((void (*)())laddr(p, v))
#endif
#define OK_TYPES (1<<STT_NOTYPE | 1<<STT_OBJECT | 1<<STT_FUNC | 1<<STT_COMMON | 1<<STT_TLS)
#define OK_BINDS (1<<STB_GLOBAL | 1<<STB_WEAK | 1<<STB_GNU_UNIQUE)
#ifndef ARCH_SYM_REJECT_UND
#define ARCH_SYM_REJECT_UND(s) 0
#endif
#if defined(__GNUC__)
#endif
#ifdef TLS_ABOVE_TP
#else
#endif
#ifdef TLS_ABOVE_TP
#else
#endif
#ifdef TLSDESC_BACKWARDS
#endif
#ifdef SYS_mmap2
#else
#endif
#ifdef TLS_ABOVE_TP
#else
#endif
#ifndef NO_LEGACY_INITFINI
#endif
#ifndef NO_LEGACY_INITFINI
#endif
#if 0
#else
#endif
#ifdef TLS_ABOVE_TP
#else
#endif
#if _REDIR_TIME64
#endif
