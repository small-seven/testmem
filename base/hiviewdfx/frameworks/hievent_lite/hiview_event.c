#include "securec.h"
#include "string.h"
#include "hos_types.h"
#include "hos_init.h"
#include "hiview_def.h"
#include "hiview_util.h"
#include "hiview_log.h"
#include "hiview_service.h"
#include "hiview_output_event.h"
#include "hiview_config.h"
#include "hiview_event.h"
#define SINGLE_VALUE_MAX_LEN   5
#define EVENT_VALUE_MAX_NUM    16
#define ENCODE_VALUE_LEN1      1
#define ENCODE_VALUE_LEN2      2
#define ENCODE_VALUE_LEN3      3
#define ENCODE_VALUE_LEN4      4
#define GET_UINT32_BYTE1(v)    (uint8)((v) & 0x000000FF)
#define GET_UINT32_BYTE2(v)    (uint8)(((v) & 0x0000FF00) >> 8)
#define GET_UINT32_BYTE3(v)    (uint8)(((v) & 0x00FF0000) >> 16)
#define GET_UINT32_BYTE4(v)    (uint8)(((v) & 0xFF000000) >> 24)
