#include "kwbimage.h"
#include "mkimage.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <image.h>
#include <libgen.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>
#include <termios.h>
#include <sys/mman.h>
#include <sys/stat.h>
#ifdef __GNUC__
#define PACKED __attribute((packed))
#else
#define PACKED
#endif
#define KWBOOT_MSG_REQ_DELAY	10 /* ms */
#define KWBOOT_MSG_RSP_TIMEO	50 /* ms */
#define KWBOOT_MSG_REQ_DELAY_AXP	1000 /* ms */
#define KWBOOT_MSG_RSP_TIMEO_AXP	1000 /* ms */
#define SOH	1	/* sender start of block header */
#define EOT	4	/* sender end of block transfer */
#define ACK	6	/* target block ack */
#define NAK	21	/* target block negative ack */
#define CAN	24	/* target/sender transfer cancellation */
#define KWBOOT_BLK_RSP_TIMEO 1000 /* ms */
