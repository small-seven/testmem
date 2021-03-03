#include "at_wifi.h"
#include <stdio.h>
#include <stdlib.h>
#include <hi_at.h>
#ifndef CONFIG_FACTORY_TEST_MODE
#include "lwip/netifapi.h"
#endif
#include "hi_early_debug.h"
#include "hi_stdlib.h"
#include "hi_wifi_api.h"
#include "hi_wifi_mfg_test_if.h"
#ifdef LOSCFG_APP_MESH
#include "hi_wifi_mesh_api.h"
#include "hi_mesh_autolink_api.h"
#endif
#include "at.h"
#ifndef CONFIG_FACTORY_TEST_MODE
#include "lwip/netifapi.h"
#include "lwip/dns.h"
#endif
#include "hi_wifi_mfg_test_if.h"
#include "at_demo_hks.h"
#include "at_general.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
#ifdef _PRE_PSK_CALC_USER
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#else
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#define CERT_PLAIN_SIZE (1024*8)
#ifdef CONFIG_WPS_SUPPORT
#endif /* LOSCFG_APP_WPS */
#ifdef CONFIG_WPS_SUPPORT
#endif /* LOSCFG_APP_WPS */
#ifdef CONFIG_TEE_HUKS_DEMO_SUPPORT
#endif
#define AT_STA_FUNC_NUM (sizeof(g_sta_func_tbl) / sizeof(g_sta_func_tbl[0]))
#ifdef CONFIG_TEE_HUKS_DEMO_SUPPORT
#endif
#define AT_STA_FACTORY_TEST_FUNC_NUM (sizeof(g_sta_factory_test_func_tbl) / sizeof(g_sta_factory_test_func_tbl[0]))
#define AT_AP_FUNC_NUM (sizeof(g_at_ap_func_tbl) / sizeof(g_at_ap_func_tbl[0]))
#ifdef LOSCFG_APP_MESH
#define AT_MESH_FUNC_NUM (sizeof(g_at_mesh_func_tbl) / sizeof(g_at_mesh_func_tbl[0]))
#endif
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
