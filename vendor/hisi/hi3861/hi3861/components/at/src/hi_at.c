#include "hi_at.h"
#include <at.h>
#include <at_cmd.h>
#include <hi_stdlib.h>
#include <hi_watchdog.h>
#include <hi_event.h>
#include <hi_lowpower.h>
#include <hi_timer.h>
#include <hi_cpu.h>
#include <sal_inf.h>
#include "at_hipriv.h"
#include "at_general.h"
#include "at_wifi.h"
#include "at_io.h"
#include "at_lowpower.h"
#include "at_printf.h"
#include "hi_uart.h"
#include "hi_task.h"
#include "serial_dw.h"
#include "securec.h"
#include "unistd.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
#define CMD_MAX_LEN                 256
#define AT_DEFAULT_UART_TASK_SIZE   0x600
#define AT_DEFAULT_PROC_TASK_SIZE   0xC00 /* 0x800:softap start would fail. */
#define AT_UART_TASK_PRIO           9
#define AT_PROC_TASK_PRIO           10
#define AT_CMD_HEADER               "AT"
#define AT_UART_SLEEP               1000
#define AT_DATA_MAX_LEN             1024
#define RECV_DATA_NORMAL_CHAR       0
#define RECV_DATA_END_CHAR          1
#define RECV_DATA_END_CHAR_REPEAT   2
#define STAT_NOMAL_KEY              0
#define STAT_ESC_KEY                1
#define STAT_MULTI_KEY              2
#define SOFT_REBOOT_MAX_BUSY_CNT    20
#define AT_WAIT_TIME 10000         /* wait 10 seconds */
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_QUICK_SEND_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#ifdef LOSCFG_APP_MESH
#endif
#endif
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
