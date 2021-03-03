#include "netif/ppp/ppp_opts.h"
#if PPP_SUPPORT /* don't build if not configured for use in lwipopts.h */
#if 0 /* UNUSED */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <syslog.h>
#include <netdb.h>
#include <time.h>
#include <utmp.h>
#include <pwd.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#ifdef SVR4
#include <sys/mkdev.h>
#endif
#endif /* UNUSED */
#include "netif/ppp/ppp_impl.h"
#include "netif/ppp/fsm.h"
#include "netif/ppp/lcp.h"
#if defined(SUNOS4)
#endif
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#define OUTCHAR(c)	(buflen > 0? (--buflen, *buf++ = (c)): 0)
#if 0 /* need port */
#endif /* need port */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if 0 /* unused (and wrong on LLP64 systems) */
#endif /* unused (and wrong on LLP64 systems) */
#if 0 /* do we always have strerror() in embedded ? */
#endif /* do we always have strerror() in embedded ? */
#if 0 /* need port */
#endif /* need port */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if 0 /* UNUSED */
#endif /* UNUSED */
#if 0
#endif
#if 0 /* UNUSED */
#endif /* UNUSED */
#if PRINTPKT_SUPPORT
#endif /* PRINTPKT_SUPPORT */
#if 0 /* Unused */
#ifndef LOCK_DIR
#ifdef __linux__
#define LOCK_DIR	"/var/lock"
#else
#ifdef SVR4
#define LOCK_DIR	"/var/spool/locks"
#else
#define LOCK_DIR	"/var/spool/lock"
#endif
#endif
#endif /* LOCK_DIR */
#ifdef LOCKLIB
#else /* LOCKLIB */
#ifdef SVR4
#else
#endif
#ifndef LOCK_BINARY
#else
#endif /* LOCK_BINARY */
#ifndef LOCK_BINARY
#endif /* LOCK_BINARY */
#ifndef LOCK_BINARY
#else
#endif
#endif
#ifdef LOCKLIB
#else /* LOCKLIB */
#ifndef LOCK_BINARY
#else
#endif /* LOCK_BINARY */
#endif /* LOCKLIB */
#ifdef LOCKLIB
#else
#endif
#endif /* Unused */
#endif /* PPP_SUPPORT */
