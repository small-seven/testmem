#include "telnet_dev.h"
#ifdef LOSCFG_NET_TELNET
#include "unistd.h"
#include "stdlib.h"
#include "sys/ioctl.h"
#include "sys/types.h"
#include "pthread.h"
#include "los_printf.h"
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#include "los_swtmr_pri.h"
#endif
#include "console.h"
#include "lwip/opt.h"
#include "lwip/sockets.h"
#include "telnet_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define TELNET_EVENT_MORE_CMD   0x01
#define TELNET_DEV_DRV_MODE     0666
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#endif
#ifndef CONFIG_DISABLE_POLL
#endif
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
