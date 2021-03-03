#include "hiview_command.h"
#include "securec.h"
#include "hos_types.h"
#include "hiview_util.h"
#include "hiview_config.h"
#include "hiview_log.h"
#define CMD_MIN_LEN     2
#define CMD_MAX_LEN     32
#define CMD_HILOGCAT    "hilog"
#define CMD_HIEVENT     "hievent"
#define OPTION_TAG      '-'
#define OPTION_LIST     'l'
#define OPTION_SET      'c'
#define OPTION_SIMULATE 's'
#define OPTION_HELP     'h'
#define PARA_LEVEL      " level"
#define PARA_LEVEL_LEN  6
#define PARA_MODULE     " mod"
#define PARA_MODULE_LEN 4
#define OP_ASSIGN       '='
#define STR_MAX_LEN     128
