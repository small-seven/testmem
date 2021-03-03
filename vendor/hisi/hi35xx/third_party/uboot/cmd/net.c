#include <common.h>
#include <command.h>
#include <env.h>
#include <net.h>
#ifdef CONFIG_CMD_BOOTP
#endif
#ifdef CONFIG_CMD_TFTPBOOT
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_CMD_TFTPSRV
#endif
#ifdef CONFIG_CMD_RARP
#endif
#if defined(CONFIG_CMD_DHCP)
#endif
#if defined(CONFIG_CMD_NFS)
#endif
#if !defined(CONFIG_BOOTP_SERVERIP)
#endif
#if defined(CONFIG_BOOTP_DNS2)
#endif
#if defined(CONFIG_CMD_SNTP) && defined(CONFIG_BOOTP_TIMEOFFSET)
#endif
#if defined(CONFIG_CMD_SNTP) && defined(CONFIG_BOOTP_NTPSERVER)
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#if defined(CONFIG_CMD_PING)
#endif
#if defined(CONFIG_CMD_CDP)
#endif
#if defined(CONFIG_CMD_SNTP)
#endif
#if defined(CONFIG_CMD_DNS)
#endif	/* CONFIG_CMD_DNS */
#if defined(CONFIG_CMD_LINK_LOCAL)
#endif  /* CONFIG_CMD_LINK_LOCAL */
