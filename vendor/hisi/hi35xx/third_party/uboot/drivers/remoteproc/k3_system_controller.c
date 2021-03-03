#include <common.h>
#include <dm.h>
#include <remoteproc.h>
#include <errno.h>
#include <mailbox.h>
#include <linux/soc/ti/k3-sec-proxy.h>
#define K3_MSG_R5_TO_M3_M3FW			0x8105
#define K3_MSG_M3_TO_R5_CERT_RESULT		0x8805
#define K3_MSG_M3_TO_R5_BOOT_NOTIFICATION	0x000A
#define K3_FLAGS_MSG_CERT_AUTH_PASS		0x555555
#define K3_FLAGS_MSG_CERT_AUTH_FAIL		0xffffff
