#include "fstream"
#include "iostream"
#include "thread"
#include "unistd.h"
#include <climits>
#include <sys/prctl.h>
#include <fcntl.h>
#include "securec.h"
#include "gtest/gtest.h"
#include "surface.h"
#include "source.h"
#include "player.h"
#include "format.h"
#define DOFUNC_STR_NORET(func, str) \
#define DOFUNC_STR_RET(func, str) \
#define IS_OK(ret) \
typedef struct TagTestSample {
    std::shared_ptr<Player> adaptr;
    pthread_t process;
    pthread_mutex_t mutex;
    int32_t isThreadRunning;
    int32_t sourceType;
    char filePath[FILE_PATH_LEN];
    std::shared_ptr<StreamSourceSample> streamSample;
} TestSample;
typedef struct TagIdleBuffer {
    size_t idx;
    size_t offset;
    size_t size;
} IdleBuffer;
#define READ_LEN  (1024)
