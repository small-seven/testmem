#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/if_tun.h>
#include "tst_test.h"
#ifndef TUNGETFEATURES
#define TUNGETFEATURES _IOR('T', 207, unsigned int)
#endif
#ifndef IFF_VNET_HDR
#define IFF_VNET_HDR	0x4000
#endif
#ifndef IFF_MULTI_QUEUE
#define IFF_MULTI_QUEUE	0x0100
#endif
#ifndef IFF_NAPI
#define IFF_NAPI	0x0010
#endif
#ifndef IFF_NAPI_FRAGS
#define IFF_NAPI_FRAGS	0x0020
#endif
