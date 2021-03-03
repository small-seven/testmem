#include <common.h>
#include <dm.h>
#include <linux/delay.h>
#include <linux/io.h>
#ifdef CONFIG_MISC_INIT_R
#define FU540_OTP_BASE_ADDR			0x10070000
#define BYTES_PER_FUSE				4
#define NUM_FUSES				0x1000
#endif
