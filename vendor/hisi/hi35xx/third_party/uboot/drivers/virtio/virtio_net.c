#include <common.h>
#include <dm.h>
#include <net.h>
#include <virtio_types.h>
#include <virtio.h>
#include <virtio_ring.h>
#include "virtio_net.h"
#define VIRTIO_NET_NUM_RX_BUFS	32
#define VIRTIO_NET_RX_BUF_SIZE	1526
