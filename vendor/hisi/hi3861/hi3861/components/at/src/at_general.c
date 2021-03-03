#include "at_general.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <at_cmd.h>
#include <cpup_diag_dfx.h>
#include <hi_at.h>
#include <hi_cpu.h>
#include <hi_crash.h>
#include <hi_flash.h>
#include <hi_mem.h>
#include <hi_mux.h>
#include <hi_nv.h>
#include <hi_os_stat.h>
#include <hi_reset.h>
#include <hi_sal_nv.h>
#include <hi_stdlib.h>
#include <hi_task.h>
#include <hi_time.h>
#include <hi_tsensor.h>
#include <hi_uart.h>
#include <hi_watchdog.h>
#include <hi_upg_api.h>
#include <hi_ver.h>
#include <hi_wifi_api.h>
#ifndef CONFIG_FACTORY_TEST_MODE
#include "lwip/netifapi.h"
#include "lwip/api_shell.h"
#include "lwip/sockets.h"
#ifdef CONFIG_IPERF_SUPPORT
#include "iperf.h"
#endif
#endif
#ifdef CONFIG_SIGMA_SUPPORT
#include "hi_wifitest.h"
#endif
#include "hi_config.h"
#include "sal_common.h"
#include "at.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
#define HI_AT_VER_FULL_PRODUCT_NAME_MAX_SIZE 100
#ifdef CONFIG_IPERF_SUPPORT
#endif
#define IP_LINK_ID_MAX            8
#define IP_TCP_SERVER_LISTEN_NUM  4           /* TCP Maximum number of clients that can be received by the server */
#define IP_RESV_BUF_LEN           1024        /* IP packet receiving buffer */
#define IP_SEND_BUF_LEN           1024        /* IP packet sending buffer, which must be the same as the value of
#define IP_MUX_WAIT_TIME          HI_SYS_WAIT_FOREVER
#define PRINT_SIZE_MAX            128
#define IP_UDP_LINK_MAX           4           /* Maximum number of manually created UDP links */
typedef struct {
    hi_s32 sfd;
    hi_u8 link_stats;
    hi_u8 link_res;
    hi_u8 ip_protocol;
    hi_u8 res;
} ip_conn_ctl_stru;
typedef struct {
    hi_s32 sfd;
    hi_u8 link_stats;
    hi_u8 res[3]; /* 3 bytes reserved */
} ip_listen_socket_stru;
typedef enum {
    IP_NULL = 0,
    IP_TCP  = 1,
    IP_UDP  = 2,

    IP_PROTOCAL_BUTT
} ip_protocol;
typedef hi_u8 ip_protocol_uint8;

typedef enum {
    IP_LINK_RES_INIT = 0, /* Initial Value */
    IP_LINK_MANUAL  = 1,  /* Creating a Link manually */
    IP_LINK_AUTO  = 2,    /* Creating Links automatically */

    IP_LINK_RES_BUTT
} ip_link_res;
typedef hi_u8 ip_link_res_uint8;

typedef enum {
    IP_LINK_ID_IDLE = 0,      /* Idle state */
    IP_LINK_WAIT_RESV,
    IP_LINK_WAIT_CLOSE,
    IP_LINK_USER_CLOSE,
    IP_LINK_SERVER_LISTEN,    /* SERVER Listening state */

    IP_LINK_STAUS_BUTT
} ip_link_stats;
typedef hi_u8 ip_link_stats_uint8;

#ifndef CONFIG_FACTORY_TEST_MODE
static ip_conn_ctl_stru g_ip_link_ctl[IP_LINK_ID_MAX];
static hi_s8 g_ip_task_exit;
static ip_listen_socket_stru g_listen_fd;
static hi_s32 g_ip_taskid = -1;
static hi_s8 g_link_id = -1;
static in_addr_t g_peer_ipaddr;
static hi_u16 g_peer_port;
static hi_u32 g_ip_mux_id;
#endif

hi_u32 at_exe_at_cmd(void)
{
    AT_RESPONSE_OK;
    return HI_ERR_SUCCESS;
}
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#else
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#ifdef CONFIG_IPERF_SUPPORT
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#if LWIP_LITEOS_TASK
#endif
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#define TSENSOR_TEMPERATURE_MAX     140       /* Maximum temperature */
#define TSENSOR_TEMPERATURE_MIN     (-40)     /* Minimum temperature */
#ifdef CONFIG_SIGMA_SUPPORT
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#ifdef CONFIG_IPERF_SUPPORT
#endif
#ifdef CONFIG_SIGMA_SUPPORT
#endif
#if LWIP_DNS
#endif
#endif
#define AT_GENERAL_FUNC_NUM (sizeof(g_at_general_func_tbl) / sizeof(g_at_general_func_tbl[0]))
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#define AT_GENERAL_FACTORY_TEST_FUNC_NUM (sizeof(g_at_general_factory_test_func_tbl) / \
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
