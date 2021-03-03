#include <common.h>
#include <command.h>
#include <net.h>
#include <malloc.h>
#include <mapmem.h>
#include "nfs.h"
#include "bootp.h"
#include <time.h>
#define HASHES_PER_LINE 65	/* Number of "loading" hashes per line	*/
#define NFS_RETRY_COUNT 30
#ifndef CONFIG_NFS_TIMEOUT
# define NFS_TIMEOUT 2000UL
#else
# define NFS_TIMEOUT CONFIG_NFS_TIMEOUT
#endif
#define NFS_RPC_ERR	1
#define NFS_RPC_DROP	124
#define STATE_PRCLOOKUP_PROG_MOUNT_REQ	1
#define STATE_PRCLOOKUP_PROG_NFS_REQ	2
#define STATE_MOUNT_REQ			3
#define STATE_UMOUNT_REQ		4
#define STATE_LOOKUP_REQ		5
#define STATE_READ_REQ			6
#define STATE_READLINK_REQ		7
#define NFSV2_FLAG 1
#define NFSV3_FLAG 1 << 1
#ifdef CONFIG_SYS_DIRECT_FLASH_NFS
#endif /* CONFIG_SYS_DIRECT_FLASH_NFS */
