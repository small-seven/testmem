#include <common.h>
#include <command.h>
#include <efi_loader.h>
#include <env.h>
#include <mapmem.h>
#include <net.h>
#include <net/tftp.h>
#include "bootp.h"
#ifdef CONFIG_SYS_DIRECT_FLASH_TFTP
#include <flash.h>
#endif
#define WELL_KNOWN_PORT	69
#define TIMEOUT		5000UL
#ifndef	CONFIG_NET_RETRY_COUNT
# define TIMEOUT_COUNT	10
#else
# define TIMEOUT_COUNT  (CONFIG_NET_RETRY_COUNT * 2)
#endif
#define HASHES_PER_LINE	65
#define TFTP_RRQ	1
#define TFTP_WRQ	2
#define TFTP_DATA	3
#define TFTP_ACK	4
#define TFTP_ERROR	5
#define TFTP_OACK	6
#ifdef CONFIG_LMB
#endif
#ifdef CONFIG_TFTP_TSIZE
#endif
#ifdef CONFIG_CMD_TFTPPUT
#else
#define tftp_put_active	0
#endif
#define STATE_SEND_RRQ	1
#define STATE_DATA	2
#define STATE_TOO_LARGE	3
#define STATE_BAD_MAGIC	4
#define STATE_OACK	5
#define STATE_RECV_WRQ	6
#define STATE_SEND_WRQ	7
#define TFTP_BLOCK_SIZE		512
#define TFTP_SEQUENCE_SIZE	((ulong)(1<<16))
#define DEFAULT_NAME_LEN	(8 + 4 + 1)
#ifndef CONFIG_TFTP_FILE_NAME_MAX_LEN
#define MAX_LEN 128
#else
#define MAX_LEN CONFIG_TFTP_FILE_NAME_MAX_LEN
#endif
#ifdef CONFIG_TFTP_BLOCKSIZE
#define TFTP_MTU_BLOCKSIZE CONFIG_TFTP_BLOCKSIZE
#else
#define TFTP_MTU_BLOCKSIZE 1468
#endif
#ifdef CONFIG_SYS_DIRECT_FLASH_TFTP
#endif /* CONFIG_SYS_DIRECT_FLASH_TFTP */
#ifdef CONFIG_LMB
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_TFTP_TSIZE
#endif
#ifdef CONFIG_TFTP_TSIZE
#endif
#ifdef CONFIG_CMD_TFTPPUT
#else
#endif
#ifdef CONFIG_TFTP_TSIZE
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_CMD_TFTPSRV
#endif
#ifdef CONFIG_TFTP_TSIZE
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_LMB
#endif
#if CONFIG_NET_TFTP_VARS
#endif
#ifdef CONFIG_CMD_TFTPPUT
#else
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_CMD_BOOTEFI
#endif
#ifdef CONFIG_CMD_TFTPPUT
#endif
#ifdef CONFIG_TFTP_PORT
#endif
#ifdef CONFIG_TFTP_TSIZE
#endif
#ifdef CONFIG_CMD_TFTPSRV
#ifdef CONFIG_TFTP_TSIZE
#endif
#endif /* CONFIG_CMD_TFTPSRV */
