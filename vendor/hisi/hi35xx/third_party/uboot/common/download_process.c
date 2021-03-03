#include <common.h>
#include <watchdog.h>
#include <command.h>
#include <serial.h>
#include <usb.h>
#ifdef DUMP_SWITCH
#endif
#define	XHEAD	0xAB
#define	XCMD	0xCD
#define	ACK     0xAA            /* ACK VALUE */
#define	NAK     0x55            /* NAK VALUE */
#define START_FRAME_LEN	5
#define MAX_BUFF_SIZE		1024
#define MAX_SEND_SIZE    20
#ifndef CONFIG_MINI_BOOT
#endif
