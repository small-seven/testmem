#include <common.h>
#include <dm.h>
#include <log.h>
#include <tee.h>
#include <mmc.h>
#include "optee_msg.h"
#include "optee_private.h"
#define RPMB_CMD_DATA_REQ      0x00
#define RPMB_CMD_GET_DEV_INFO  0x01
#define RPMB_REQ_DATA(req) ((void *)((struct rpmb_req *)(req) + 1))
#define RPMB_CMD_GET_DEV_INFO_RET_OK     0x00
#define RPMB_CMD_GET_DEV_INFO_RET_ERROR  0x01
