#include <cpu_func.h>
#include <console.h>
#include "higmac.h"
#include "ctrl.h"
#include "mdio.h"
typedef enum {
	GSF0_PORT0,
#if GMAC_AT_LEAST_2PORT
	GSF0_PORT1,
#endif
#if GMAC_AT_LEAST_3PORT
	GSF1_PORT0,
#endif
	MAX_PORT_NUM,
} port_id_t;
#if GMAC_AT_LEAST_2PORT
#endif
#if GMAC_AT_LEAST_3PORT
#endif
#define MDIO_BUS_NUMS				2
#if GMAC_AT_LEAST_2PORT
#endif
#if GMAC_AT_LEAST_2PORT
#endif
#if GMAC_AT_LEAST_3PORT
#endif
#if defined(CONFIG_MACH_GODEYES)
#else
#endif
#if GMAC_AT_LEAST_2PORT
#endif
#if GMAC_AT_LEAST_2PORT
#else
#endif
#if GMAC_AT_LEAST_2PORT
#endif
#if GMAC_AT_LEAST_2PORT
#else
#endif
#if GMAC_AT_LEAST_2PORT
#endif
#ifdef CONFIG_NET_RANDOM_ETHADDR
#endif
#ifndef CONFIG_SYS_DCACHE_OFF
#endif
#define PHY_ID_KSZ8051		0x00221550
#define PHY_ID_KSZ8081		0x00221560
#define PHY_ID_KSZ9031		0x00221620
#define PHY_ID_MASK		0xFFFFFFF0
#define MACR			0x0D
#define MAADR			0x0E
#define NET_IP_ALIGN	2
#ifndef CONFIG_SYS_DCACHE_OFF
#endif
#if defined(CONFIG_64BIT)
#endif
#ifndef CONFIG_SYS_DCACHE_OFF
#endif
#ifndef CONFIG_SYS_DCACHE_OFF
#endif
#if defined(CONFIG_64BIT)
#endif
#ifndef CONFIG_SYS_DCACHE_OFF
#endif
#if defined(CONFIG_64BIT)
#endif
#ifndef CONFIG_SYS_DCACHE_OFF
#endif
#ifdef CFG_NET_PINCTRL
#if GMAC_AT_LEAST_2PORT
#endif
#if GMAC_AT_LEAST_2PORT
#endif
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#ifdef CFG_NET_PINCTRL
#endif
#if GMAC_AT_LEAST_2PORT
#endif
#if GMAC_AT_LEAST_3PORT
#endif
