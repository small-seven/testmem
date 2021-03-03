#include <common.h>
#include <command.h>
#include <env.h>
#include <efi_loader.h>
#include <net.h>
#include <net/tftp.h>
#include "bootp.h"
#ifdef CONFIG_LED_STATUS
#include <status_led.h>
#endif
#ifdef CONFIG_BOOTP_RANDOM_DELAY
#include "net_rand.h"
#endif
#define BOOTP_VENDOR_MAGIC	0x63825363	/* RFC1048 Magic Cookie */
#ifndef CONFIG_NET_RETRY_COUNT
# define TIMEOUT_COUNT	5		/* # of timeouts before giving up */
#else
# define TIMEOUT_COUNT	(CONFIG_NET_RETRY_COUNT)
#endif
#define TIMEOUT_MS	((3 + (TIMEOUT_COUNT * 5)) * 1000)
#define PORT_BOOTPS	67		/* BOOTP server UDP port */
#define PORT_BOOTPC	68		/* BOOTP client UDP port */
#ifndef CONFIG_DHCP_MIN_EXT_LEN		/* minimal length of extension list */
#define CONFIG_DHCP_MIN_EXT_LEN 64
#endif
#ifndef CONFIG_BOOTP_ID_CACHE_SIZE
#define CONFIG_BOOTP_ID_CACHE_SIZE 4
#endif
#if defined(CONFIG_CMD_DHCP)
#define OVERLOAD_FILE 1
#define OVERLOAD_SNAME 2
#if 0
#endif
#endif
#if !defined(CONFIG_BOOTP_SERVERIP)
#if defined(CONFIG_BOOTP_PREFER_SERVERIP)
#endif
#if defined(CONFIG_CMD_DHCP)
#endif
#endif
#if !defined(CONFIG_CMD_DHCP)
#if defined(CONFIG_BOOTP_DNS2)
#endif
#if defined(CONFIG_CMD_SNTP) && defined(CONFIG_BOOTP_NTPSERVER)
#endif
#if defined(CONFIG_CMD_SNTP) && defined(CONFIG_BOOTP_NTPSERVER)
#endif
#if defined(CONFIG_LED_STATUS) && defined(CONFIG_LED_STATUS_BOOT_ENABLE)
#endif
#endif
#ifdef CONFIG_BOOTP_MAY_FAIL
#endif
#define put_vci(e, str)						\
#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_NET_VCI_STRING)
#elif defined(CONFIG_BOOTP_VCI_STRING)
#endif
#if defined(CONFIG_CMD_DHCP)
#ifdef CONFIG_LIB_UUID
#endif
#if defined(CONFIG_BOOTP_VENDOREX)
#endif
#if defined(CONFIG_BOOTP_SEND_HOSTNAME)
#endif
#if defined(CONFIG_BOOTP_SEND_HOSTNAME)
#endif
#ifdef CONFIG_BOOTP_PXE_CLIENTARCH
#endif
#ifdef CONFIG_LIB_UUID
#endif
#if defined(CONFIG_BOOTP_VENDOREX)
#endif
#if defined(CONFIG_BOOTP_SUBNETMASK)
#endif
#if defined(CONFIG_BOOTP_TIMEOFFSET)
#endif
#if defined(CONFIG_BOOTP_GATEWAY)
#endif
#if defined(CONFIG_BOOTP_DNS)
#endif
#if defined(CONFIG_BOOTP_HOSTNAME)
#endif
#if defined(CONFIG_BOOTP_BOOTFILESIZE)
#endif
#if defined(CONFIG_BOOTP_BOOTPATH)
#endif
#if defined(CONFIG_BOOTP_NISDOMAIN)
#endif
#if defined(CONFIG_BOOTP_NTPSERVER)
#endif
#ifdef	CONFIG_DHCP_MIN_EXT_LEN
#endif
#else
#if defined(CONFIG_CMD_DHCP)
#endif
#if defined(CONFIG_BOOTP_SUBNETMASK)
#endif
#if defined(CONFIG_BOOTP_GATEWAY)
#endif
#if defined(CONFIG_BOOTP_DNS)
#endif
#if defined(CONFIG_BOOTP_HOSTNAME)
#endif
#if defined(CONFIG_BOOTP_BOOTFILESIZE)
#endif
#if defined(CONFIG_BOOTP_BOOTPATH)
#endif
#if defined(CONFIG_BOOTP_NISDOMAIN)
#endif
#if defined(CONFIG_BOOTP_NTPSERVER)
#endif
#endif
#ifdef CONFIG_BOOTP_RANDOM_DELAY
#endif
#if defined(CONFIG_CMD_DHCP)
#endif
#ifdef CONFIG_BOOTP_RANDOM_DELAY		/* Random BOOTP delay */
#endif	/* CONFIG_BOOTP_RANDOM_DELAY */
#if defined(CONFIG_CMD_DHCP)
#else
#endif
#if defined(CONFIG_CMD_DHCP)
#else
#endif
#if defined(CONFIG_CMD_DHCP)
#if defined(CONFIG_CMD_SNTP) && defined(CONFIG_BOOTP_TIMEOFFSET)
#endif
#if defined(CONFIG_CMD_SNTP) && defined(CONFIG_BOOTP_TIMEOFFSET)
#endif
#if defined(CONFIG_BOOTP_DNS2)
#endif
#if defined(CONFIG_CMD_SNTP) && defined(CONFIG_BOOTP_NTPSERVER)
#endif
#if defined(CONFIG_BOOTP_VENDOREX)
#endif
#ifdef CONFIG_BOOTP_DHCP_REQUEST_DELAY
#endif	/* CONFIG_BOOTP_DHCP_REQUEST_DELAY */
#ifdef CONFIG_SYS_BOOTFILE_PREFIX
#endif	/* CONFIG_SYS_BOOTFILE_PREFIX */
#ifdef CONFIG_SYS_BOOTFILE_PREFIX
#endif	/* CONFIG_SYS_BOOTFILE_PREFIX */
#endif	/* CONFIG_CMD_DHCP */
