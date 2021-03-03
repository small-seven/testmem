#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include "tst_test.h"
#include "uevent.h"
#define TUN_PATH "/dev/net/tun"
