#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/prctl.h>
#include "source.h"
#include "player.h"
#include "format.h"
#include <string>
#include <sys/prctl.h>
#include "securec.h"
#define DOFUNC_STR_NORET(func , str)  \
#define DOFUNC_STR_RET(func , str)  \
#define IS_OK(ret) \
#define SAMPLE_RETURN_VAL_IF_NULL(condition)                                           \
typedef struct TagTestSample
{
    std::shared_ptr<Player> adapter;
    pthread_t process;
    pthread_mutex_t mutex;
    int32_t isThreadRunning;
    int32_t sourceType;
    char filePath[PATH_MAX];
    std::shared_ptr<StreamSourceSample> streamSample;
} TestSample;
typedef struct TagIdleBuffer{
    size_t idx;
    size_t offset;
    size_t size;
} IdleBuffer;
#define READ_LEN  (1024)
