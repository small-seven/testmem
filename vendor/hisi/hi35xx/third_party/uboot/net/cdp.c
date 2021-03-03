#include <common.h>
#include <net.h>
#if defined(CONFIG_CDP_VERSION)
#include <timestamp.h>
#endif
#include "cdp.h"
#define CDP_DEVICE_ID_TLV		0x0001
#define CDP_ADDRESS_TLV			0x0002
#define CDP_PORT_ID_TLV			0x0003
#define CDP_CAPABILITIES_TLV		0x0004
#define CDP_VERSION_TLV			0x0005
#define CDP_PLATFORM_TLV		0x0006
#define CDP_NATIVE_VLAN_TLV		0x000a
#define CDP_APPLIANCE_VLAN_TLV		0x000e
#define CDP_TRIGGER_TLV			0x000f
#define CDP_POWER_CONSUMPTION_TLV	0x0010
#define CDP_SYSNAME_TLV			0x0014
#define CDP_SYSOBJECT_TLV		0x0015
#define CDP_MANAGEMENT_ADDRESS_TLV	0x0016
#define CDP_TIMEOUT			250UL	/* one packet every 250ms */
#if	defined(CONFIG_CDP_DEVICE_ID) || defined(CONFIG_CDP_PORT_ID)   || \
#endif
#ifdef CONFIG_CDP_DEVICE_ID
#endif
#ifdef CONFIG_CDP_PORT_ID
#endif
#ifdef CONFIG_CDP_CAPABILITIES
#endif
#ifdef CONFIG_CDP_VERSION
#endif
#ifdef CONFIG_CDP_PLATFORM
#endif
#ifdef CONFIG_CDP_TRIGGER
#endif
#ifdef CONFIG_CDP_POWER_CONSUMPTION
#endif
#ifdef CONFIG_CDP_APPLIANCE_VLAN_TYPE
#else
#endif
