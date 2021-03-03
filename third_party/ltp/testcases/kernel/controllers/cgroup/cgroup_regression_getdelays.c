#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <poll.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <signal.h>
#include <linux/types.h>
#include "config.h"
#ifdef HAVE_LINUX_GENETLINK_H
#include <linux/genetlink.h>
#endif
#ifdef HAVE_LINUX_TASKSTATS_H
#include <linux/taskstats.h>
#endif
#ifdef HAVE_LINUX_CGROUPSTATS_H
#include <linux/cgroupstats.h>
#endif
#if defined(HAVE_LINUX_GENETLINK_H) && defined(HAVE_LINUX_TASKSTATS_H)
#define GENLMSG_DATA(glh)	((void *)(NLMSG_DATA(glh) + GENL_HDRLEN))
#define GENLMSG_PAYLOAD(glh)	(NLMSG_PAYLOAD(glh, 0) - GENL_HDRLEN)
#define NLA_DATA(na)		((void *)((char*)(na) + NLA_HDRLEN))
#define NLA_PAYLOAD(len)	(len - NLA_HDRLEN)
#define err(code, fmt, arg...)			\
#define PRINTF(fmt, arg...) {			\
#define MAX_MSG_SIZE	1024
#define MAX_CPUS	32
#ifdef HAVE_STRUCT_TASKSTATS_FREEPAGES_COUNT
#endif
#ifdef HAVE_STRUCT_TASKSTATS_FREEPAGES_COUNT
#endif
#ifdef HAVE_STRUCT_TASKSTATS_NVCSW
#endif
#ifdef HAVE_LINUX_CGROUPSTATS_H
#endif
#ifdef HAVE_STRUCT_TASKSTATS_READ_BYTES
#endif
#ifdef HAVE_LINUX_CGROUPSTATS_H
#else
#endif
#if HAVE_LINUX_CGROUPSTATS_H
#endif
#else
#endif
