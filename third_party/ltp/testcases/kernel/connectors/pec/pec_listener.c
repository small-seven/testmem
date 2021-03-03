#include <sys/socket.h>
#include <sys/poll.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <linux/types.h>
#include <linux/netlink.h>
#ifndef NETLINK_CONNECTOR
#else
#include <linux/connector.h>
#ifndef CN_IDX_PROC
#else
#define _LINUX_TIME_H
#include <linux/cn_proc.h>
#define PEC_MSG_SIZE (sizeof(struct cn_msg) + sizeof(struct proc_event))
#define PEC_CTRL_MSG_SIZE (sizeof(struct cn_msg) + sizeof(enum proc_cn_mcast_op))
#define MAX_MSG_SIZE 256
#endif /* CN_IDX_PROC */
#endif /* NETLINK_CONNECTOR */
