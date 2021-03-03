#include "linux/kernel.h"
#include "linux/module.h"
#include "math.h"
#include "limits.h"
#include "sys/statfs.h"
#include "los_sys_pri.h"
#include "los_swtmr.h"
#ifdef LOSCFG_KERNEL_DYNLOAD
#include "los_ld_elflib.h"
#endif
#ifdef LOSCFG_NET_LWIP_SACK
#include "lwip/sockets.h"
#include "lwip/api.h"
#include "lwip/netdb.h"
#endif
#include "linux/rbtree.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#ifdef __LP64__
#endif
#define MAX_JIFFY_OFFSET ((LONG_MAX >> 1) - 1)
#if (HZ <= OS_SYS_MS_PER_SECOND) && !(OS_SYS_MS_PER_SECOND % HZ)
#else
#endif
#define MAX_SCHEDULE_TIMEOUT UINT_MAX
#ifdef __LP64__
#endif
#undef RB_ROOT
#define RB_ROOT(head)   (head)->rbh_root
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
