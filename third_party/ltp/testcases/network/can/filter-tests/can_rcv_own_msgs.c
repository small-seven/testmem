#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <net/if.h>
#include "config.h"
#include "tst_res_flags.h"
#include "tst_minmax.h"
#ifdef HAVE_LINUX_CAN_H
#include <linux/can.h>
#include <linux/can/raw.h>
#else
#endif /* HAVE_LINUX_CAN_H */
