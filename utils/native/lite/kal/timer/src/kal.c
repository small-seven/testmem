#include "kal.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KAL_TASK_NAME_LEN 32
#define LOSCFG_BASE_CORE_MS_PER_SECOND 1000
#define OS_SYS_NS_PER_SECOND 1000000000
typedef struct {
    timer_t timerPtr;
    KalTimerType type;
    unsigned int millisec;
    KalTimerProc func;
    union sigval arg;
    int isRunning;
}KalTimer;
