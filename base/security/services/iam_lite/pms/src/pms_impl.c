#include "pms.h"
#include <fcntl.h>
#include <limits.h>
#include <pthread.h>
#include <securec.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "cJSON.h"
#include "log.h"
#include "feature.h"
#include "iunknown.h"
#include "memory_adapter.h"
#include "samgr_lite.h"
#include "service.h"
#include "perm_operate.h"
#define P_DIR "/storage/app/etc/permissions/"
#define P_NAME_MAXLEN 32
#define BUFF_SIZE 1024
#define PERM_MAX 1024
#define FIELD_PERMISSION "permissions"
#define FIELD_NAME "name"
#define FIELD_DESC "desc"
#define FIELD_IS_GRANTED "isGranted"
