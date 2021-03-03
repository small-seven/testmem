#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "log.h"
#include "securec.h"
#define HILOG_DRIVER "/dev/hilog"
#define HILOG_LOGBUFFER 1024
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0xD002D00
#define LOG_TAG "hilogcat"
#define CMD_MIN_LEN 2
#define CMD_MAX_LEN 32
#define CMD_HILOGCAT "hilog"
#define CMD_HIEVENT "hievent"
#define OPTION_TAG '-'
#define OPTION_LIST 'l'
#define OPTION_SET 'C'
#define OPTION_SIMULATE 's'
#define OPTION_HELP 'h'
#define OPTION_2_FILE 'f'
#define OPTION_START 't'
#define OPTION_UART 'R'
#define PARA_LEVEL "level"
#define PARA_LEVEL_LEN 5
#define PARA_MODULE "mod"
#define PARA_MODULE_LEN 3
#define OP_ASSIGN '='
#define STR_MAX_LEN 128
typedef struct {
    const unsigned char outputOption : 4; /* Control log output mode. Cannot be modified during running. */
    unsigned char hiviewInited : 1;       /* Indicates whether the hiview service is inited. */
    unsigned char level : 3;              /* Control log output level. HILOG_LV_XXX */
    unsigned char logSwitch : 1;          /* Indicates whether to enable the log component. */
    unsigned char eventSwitch : 1;        /* Indicates whether to enable the event component. */
    unsigned char dumpSwitch : 1;         /* Indicates whether to enable the dump component. */
    unsigned char logOutputModule;        /* Control log output module. */
    unsigned short writeFailureCount;
} HiviewConfig;
typedef enum {
    OUTPUT_OPTION_DEBUG = 0, /* Output to the UART without buffer. Commercial versions are forbidden. */
    OUTPUT_OPTION_FLOW,      /* Output to UART via SAMR */
    OUTPUT_OPTION_TEXT_FILE,
    OUTPUT_OPTION_BIN_FILE,
    OUTPUT_OPTION_MAX
} HiviewOutputOption;
#define HIVIEW_FEATURE_ON 1
#define HIVIEW_FEATURE_OFF 0
#define HILOG_MODULE_ALL 0xff
#define HILOG_MODULE_MAX_NUM 50
#define DOMIAN_ID_LENTH 6
#define ARG2 1
#define ARG3 2
#define ARG4 3
#define MODULE_OFFSET 2
