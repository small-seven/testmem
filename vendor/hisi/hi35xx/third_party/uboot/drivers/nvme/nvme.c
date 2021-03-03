#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <memalign.h>
#include <pci.h>
#include <time.h>
#include <dm/device-internal.h>
#include "nvme.h"
#define NVME_Q_DEPTH		2
#define NVME_AQ_DEPTH		2
#define NVME_SQ_SIZE(depth)	(depth * sizeof(struct nvme_command))
#define NVME_CQ_SIZE(depth)	(depth * sizeof(struct nvme_completion))
#define ADMIN_TIMEOUT		60
#define IO_TIMEOUT		30
#define MAX_PRP_POOL		512
