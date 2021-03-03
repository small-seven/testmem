#include <common.h>
#include <command.h>
#include <config.h>
#include <cpu_func.h>
#include <net.h>
#include <malloc.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <usb/fotg210.h>
#define CFG_NUM_ENDPOINTS		4
#define CFG_EP0_MAX_PACKET_SIZE	64
#define CFG_EPX_MAX_PACKET_SIZE	512
#define CFG_CMD_TIMEOUT (CONFIG_SYS_HZ >> 2) /* 250 ms */
#define CX_IDLE		0
#define CX_FINISH	1
#define CX_STALL	2
