#include <common.h>
#include <command.h>
#include <console.h>
#include <env.h>
#include <env_internal.h>
#include <errno.h>
#include <net.h>
#include <net/fastboot.h>
#include <net/tftp.h>
#if defined(CONFIG_CMD_PCAP)
#include <net/pcap.h>
#endif
#if defined(CONFIG_LED_STATUS)
#include <miiphy.h>
#include <status_led.h>
#endif
#include <watchdog.h>
#include <linux/compiler.h>
#include "arp.h"
#include "bootp.h"
#include "cdp.h"
#if defined(CONFIG_CMD_DNS)
#include "dns.h"
#endif
#include "link_local.h"
#include "nfs.h"
#include "ping.h"
#include "rarp.h"
#if defined(CONFIG_CMD_SNTP)
#include "sntp.h"
#endif
#if defined(CONFIG_CMD_WOL)
#include "wol.h"
#endif
#if defined(CONFIG_BOOTP_DNS2)
#endif
#if defined(CONFIG_API) || defined(CONFIG_EFI_LOADER)
#endif
#if defined(CONFIG_CMD_SNTP)
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#if defined(CONFIG_CMD_DNS)
#endif
#if defined(CONFIG_CMD_NFS) && !defined(CONFIG_SPL_BUILD)
#ifdef CONFIG_BOOTP_SERVERIP
#else
#endif
#endif
#ifdef CONFIG_BOOTP_SERVERIP
#else
#endif
#ifdef CONFIG_USB_KEYBOARD
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_CMD_TFTPSRV
#endif
#ifdef CONFIG_UDP_FUNCTION_FASTBOOT
#endif
#if defined(CONFIG_CMD_DHCP)
#endif
#if defined(CONFIG_CMD_RARP)
#endif
#if defined(CONFIG_CMD_PING)
#endif
#if defined(CONFIG_CMD_NFS) && !defined(CONFIG_SPL_BUILD)
#endif
#if defined(CONFIG_CMD_CDP)
#endif
#if defined(CONFIG_NETCONSOLE) && !defined(CONFIG_SPL_BUILD)
#endif
#if defined(CONFIG_CMD_SNTP)
#endif
#if defined(CONFIG_CMD_DNS)
#endif
#if defined(CONFIG_CMD_LINK_LOCAL)
#endif
#if defined(CONFIG_CMD_WOL)
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#if	defined(CONFIG_SYS_FAULT_ECHO_LINK_DOWN)	&& \
#endif /* CONFIG_SYS_FAULT_ECHO_LINK_DOWN, ... */
#endif /* CONFIG_MII, ... */
#ifdef CONFIG_USB_KEYBOARD
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#if	defined(CONFIG_SYS_FAULT_ECHO_LINK_DOWN)	&& \
#endif /* CONFIG_SYS_FAULT_ECHO_LINK_DOWN, ... */
#endif /* CONFIG_MII, ... */
#ifdef CONFIG_USB_KEYBOARD
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#if defined(CONFIG_CMD_PCAP)
#endif
#if !defined(CONFIG_NET_DO_NOT_TRY_ANOTHER)
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_IP_DEFRAG
#ifndef CONFIG_NET_MAXDEFRAG
#define CONFIG_NET_MAXDEFRAG 16384
#endif
#define IP_PKTSIZE (CONFIG_NET_MAXDEFRAG)
#define IP_MAXUDP (IP_PKTSIZE - IP_HDR_SIZE)
#else /* !CONFIG_IP_DEFRAG */
#endif
#if defined(CONFIG_CMD_PING)
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#if defined(CONFIG_CMD_CDP)
#endif
#if defined(CONFIG_CMD_PCAP)
#endif
#if defined(CONFIG_API) || defined(CONFIG_EFI_LOADER)
#endif
#if defined(CONFIG_CMD_CDP)
#endif
#if defined(CONFIG_CMD_CDP)
#endif
#if defined(CONFIG_CMD_CDP)
#endif
#ifdef CONFIG_CMD_RARP
#endif
#ifdef CONFIG_UDP_CHECKSUM
#endif
#if defined(CONFIG_NETCONSOLE) && !defined(CONFIG_SPL_BUILD)
#endif
#ifdef CONFIG_CMD_WOL
#endif
#if defined(CONFIG_CMD_PING)
#endif
#if defined(CONFIG_CMD_SNTP)
#endif
#if defined(CONFIG_CMD_DNS)
#endif
#if defined(CONFIG_CMD_NFS)
#endif
#if	defined(CONFIG_CMD_PING) || defined(CONFIG_CMD_SNTP) || \
#endif
#ifdef CONFIG_CMD_RARP
#endif
#if	defined(CONFIG_CMD_NFS)		|| \
#endif
