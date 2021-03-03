#include "app_main.h"
#include <hi3861_platform.h>
#include <hi_mdm.h>
#include <hi_flash.h>
#include <hi_nv.h>
#include <hi_lowpower.h>
#include <hi_diag.h>
#include <hi_crash.h>
#include <hi_sal.h>
#include <hi_shell.h>
#if defined(CONFIG_AT_COMMAND) || defined(CONFIG_FACTORY_TEST_MODE)
#include <hi_at.h>
#endif
#include <hi_fs.h>
#include <hi_partition_table.h>
#include <hi_ver.h>
#include <hi_cpu.h>
#include <hi_crash.h>
#ifdef CONFIG_DMA_SUPPORT
#include <hi_dma.h>
#endif
#ifdef CONFIG_I2C_SUPPORT
#include <hi_i2c.h>
#endif
#ifdef CONFIG_I2S_SUPPORT
#include <hi_i2s.h>
#endif
#ifdef CONFIG_SPI_SUPPORT
#include <hi_spi.h>
#endif
#ifdef CONFIG_PWM_SUPPORT
#include <hi_pwm.h>
#endif
#ifdef CONFIG_SDIO_SUPPORT
#include <hi_sdio_slave.h>
#include <hi_watchdog.h>
#include <app_demo_sdio_slave.h>
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#include "lwip/opt.h"
#include "lwip/ip_addr.h"
#include "lwip/netifapi.h"
#endif
#include "app_demo_upg_verify.h"
#include "hi_wifi_api.h"
#ifdef CONFIG_HILINK
#include "hilink.h"
#endif
#define APP_DEMO_RELEASE_MEM_TASK_SIZE 0x200
#define APP_DEMO_RELEASE_MEM_TASK_PRIO 0x3
#define APP_INIT_EVENT_NUM  4
#define APP_INIT_VAP_NUM    2
#ifdef CONFIG_MESH_SUPPORT
#define APP_INIT_USR_NUM    6
#else
#define APP_INIT_USR_NUM    2
#endif
#define PERIPHERAL_INIT_ERR_FLASH   (1 << 0)
#define PERIPHERAL_INIT_ERR_UART0   (1 << 1)
#define PERIPHERAL_INIT_ERR_UART1   (1 << 2)
#define PERIPHERAL_INIT_ERR_UART2   (1 << 3)
#define PERIPHERAL_INIT_ERR_IO      (1 << 4)
#define PERIPHERAL_INIT_ERR_CIPHER  (1 << 5)
#define PERIPHERAL_INIT_ERR_DMA     (1 << 6)
#define PERIPHERAL_INIT_ERR_I2C     (1 << 7)
#define PERIPHERAL_INIT_ERR_I2S     (1 << 8)
#define PERIPHERAL_INIT_ERR_SPI     (1 << 9)
#define PERIPHERAL_INIT_ERR_PWM     (1 << 10)
#define PERIPHERAL_INIT_ERR_SDIO    (1 << 11)
#ifndef IO_CTRL_REG_BASE_ADDR
#define IO_CTRL_REG_BASE_ADDR 0x904
#endif
#define iocfg_reg_addr(_x) (HI_IOCFG_REG_BASE + IO_CTRL_REG_BASE_ADDR + (_x) * 4)
#define IOCFG_LOWPOWER_CFG_VAL 0xF8
#ifdef CONFIG_SDIO_SUPPORT
#define APP_SDIO_INIT_TASK_SIZE 0x1000
#define APP_SDIO_INIT_TASK_PRIO 25
#endif
#define CLKEN_I2C0      14
#define CLKEN_I2C1      15
#define CLKEN_SPI0      5
#define CLKEN_SPI1      0
#define CLKEN_MONITOR   6
#define CLKEN_DMA_WBUS  1
#define CLKEN1_PWM5     10
#define CLKEN1_PWM_BUS  6
#define CLKEN1_PWM      5
#define CLKEN1_PWM4     4
#define CLKEN1_PWM3     3
#define CLKEN1_PWM2     2
#define CLKEN1_PWM1     1
#define CLKEN1_PWM0     0
#define CLKEN1_PWM_ALL  ((1 << (CLKEN1_PWM0)) | (1 << (CLKEN1_PWM1)) | (1 << (CLKEN1_PWM2)) | (1 << (CLKEN1_PWM3)) | \
#define CLKEN2_I2S_BUS  11
#define CLKEN2_I2S      10
#define CLKEN_UART2     6
#define CLKEN_UART2_BUS 9
#define CLKEN_TIMER1    7
#define CLKEN_TIMER2    8
#define CLKEN_SDIO_WBUS 4
#ifndef CONFIG_PWM_HOLD_AFTER_REBOOT
#endif
#ifdef CONFIG_SDIO_SUPPORT
#else
#endif
#ifdef CONFIG_DMA_SUPPORT
#endif
#ifdef CONFIG_I2C_SUPPORT
#endif
#ifdef CONFIG_I2S_SUPPORT
#endif
#ifdef CONFIG_SPI_SUPPORT
#endif
#ifdef CONFIG_PWM_SUPPORT
#endif
#ifdef AT_DEBUG_CMD_SUPPORT
#endif
#ifdef CONFIG_SDIO_SUPPORT
#endif
#ifdef AT_DEBUG_CMD_SUPPORT
#endif
#ifdef AT_DEBUG_CMD_SUPPORT
#endif
#ifdef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#if defined(CONFIG_AT_COMMAND) || defined(CONFIG_FACTORY_TEST_MODE)
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#ifndef ENABLE_SHELL_DEBUG
#ifdef CONFIG_DIAG_SUPPORT
#endif
#else
#endif
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#ifdef CONFIG_HILINK
#endif
#endif
