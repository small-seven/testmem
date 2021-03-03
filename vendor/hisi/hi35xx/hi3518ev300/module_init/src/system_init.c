#include "sys_config.h"
#include "board.h"
#include "los_typedef.h"
#include "los_typedef.h"

#include "stdlib.h"
#include "stdio.h"
#include "los_process_pri.h"
#include "disk.h"
#include "los_rootfs.h"
#ifdef LOSCFG_DRIVERS_VIDEO
#include "fb.h"
#endif
#ifdef LOSCFG_SHELL
#include "shell.h"
#include "shcmd.h"
#endif

#ifdef LOSCFG_DRIVERS_HDF_PLATFORM_UART
#include "console.h"
#include "hisoc/uart.h"
#endif

#ifdef LOSCFG_DRIVERS_HDF
#include "devmgr_service_start.h"
#endif

#ifdef LOSCFG_DRIVERS_USB
#include "implementation/usb_init.h"
#endif

#ifdef LOSCFG_DRIVERS_NETDEV
#include "lwip/tcpip.h"
#include "lwip/netif.h"
#include "lwip/netifapi.h"

#define SLEEP_TIME_MS 60
#define NETIF_SETUP_OVERTIME 100

void net_init(void)
{
    struct netif *pnetif;

extern void tcpip_init(tcpip_init_done_fn initfunc, void *arg);
    dprintf("\ntcpip_init start\n");
    tcpip_init(NULL, NULL);
    dprintf("\ntcpip_init end\n");

    static unsigned int overtime = 0;
    PRINTK("Ethernet start.");

#ifdef LOSCFG_DRIVERS_HIGMAC
    extern int ethnet_higmac_init(void);
    (void)ethnet_higmac_init();
#endif

#ifdef LOSCFG_DRIVERS_HIETH_SF
    extern int ethnet_hieth_init(void);
    (void)ethnet_hieth_init();
#endif

    extern void get_defaultNetif(struct netif **pnetif);
    get_defaultNetif(&pnetif);

    (void)netifapi_netif_set_up(pnetif);
    do {
        LOS_Msleep(SLEEP_TIME_MS);
        overtime++;
        if (overtime > NETIF_SETUP_OVERTIME) {
            PRINTK("netif_is_link_up overtime!\n");
            break;
        }
#endif
#ifdef LOSCFG_PLATFORM_HISI_AMP
#ifndef LOSCFG_ARCH_CORTEX_M7
#endif
#endif
#ifdef LOSCFG_DRIVERS_RANDOM
#endif
#ifdef LOSCFG_FS_PROC
#endif
#ifdef LOSCFG_DRIVERS_MMC
#endif
#ifdef LOSCFG_DRIVERS_MEM
#endif
#ifndef LOSCFG_DRIVERS_HDF
#ifdef LOSCFG_DRIVERS_GPIO
#endif
#endif
#ifdef LOSCFG_DRIVERS_HIEDMAC
#endif
#ifdef LOSCFG_DRIVERS_HIDMAC
#endif
#ifdef LOSCFG_DRIVERS_MTD_NAND
#endif
#ifdef LOSCFG_DRIVERS_MTD_SPI_NOR
#endif
#ifdef LOSCFG_DRIVERS_NETDEV
#endif
#ifdef LOSCFG_DRIVERS_USB
#endif
#ifndef LOSCFG_DRIVERS_HDF_PLATFORM_HISI_SDK
#endif
#ifdef LOSCFG_PLATFORM_ROOTFS
#endif
#ifdef LOSCFG_DRIVERS_HDF
#endif
#ifdef LOSCFG_DRIVERS_HDF_PLATFORM_UART
#endif
#ifdef LOSCFG_SHELL
#endif
