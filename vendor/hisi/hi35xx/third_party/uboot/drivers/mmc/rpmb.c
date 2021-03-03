#include <config.h>
#include <common.h>
#include <memalign.h>
#include <mmc.h>
#include <u-boot/sha256.h>
#include "mmc_private.h"
#define RPMB_REQ_KEY		1
#define RPMB_REQ_WCOUNTER	2
#define RPMB_REQ_WRITE_DATA	3
#define RPMB_REQ_READ_DATA	4
#define RPMB_REQ_STATUS		5
#define RPMB_RESP_KEY		0x0100
#define RPMB_RESP_WCOUNTER	0x0200
#define RPMB_RESP_WRITE_DATA	0x0300
#define RPMB_RESP_READ_DATA	0x0400
#define RPMB_OK			0
#define RPMB_ERR_GENERAL	1
#define RPMB_ERR_AUTH	2
#define RPMB_ERR_COUNTER	3
#define RPMB_ERR_ADDRESS	4
#define RPMB_ERR_WRITE		5
#define RPMB_ERR_READ		6
#define RPMB_ERR_KEY		7
#define RPMB_ERR_CNT_EXPIRED	0x80
#define RPMB_ERR_MSK		0x7
#define RPMB_SZ_STUFF		196
#define RPMB_SZ_MAC		32
#define RPMB_SZ_DATA		256
#define RPMB_SZ_NONCE		16
#define SHA256_BLOCK_SIZE	64
#ifdef CONFIG_MMC_RPMB_TRACE
#endif
#ifdef CONFIG_MMC_RPMB_TRACE
#endif
#ifdef CONFIG_MMC_RPMB_TRACE
#endif
#ifdef CONFIG_MMC_RPMB_TRACE
#endif
#ifdef CONFIG_MMC_RPMB_TRACE
#endif
