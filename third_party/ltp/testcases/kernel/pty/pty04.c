#define _GNU_SOURCE
#include "config.h"
#include "tst_test.h"
#include "tst_buffers.h"
#include "lapi/tty.h"
#if defined(HAVE_LINUX_IF_PACKET_H) && defined(HAVE_LINUX_IF_ETHER_H)
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/tty.h>
#define CAN_MTU		(sizeof(struct can_frame))
#define CAN_MAX_DLEN 8
typedef uint32_t canid_t;

struct can_frame {
	canid_t can_id;
	uint8_t can_dlc;
	uint8_t __pad;
	uint8_t __res0;
	uint8_t __res1;
	uint8_t data[CAN_MAX_DLEN] __attribute__((aligned(8)));
};
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include "lapi/ioctl.h"
#include "tst_safe_stdio.h"
#define str(s) #s
#define SLCAN_FRAME "t00185f5f5f5f5f5f5f5f\r"
#else
#endif
