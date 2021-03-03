#include "thread_adapter.h"
#include "common.h"
#include <los_task.h>
#include <cmsis_os.h>
ThreadId THREAD_Create(Runnable run, void *argv, const ThreadAttr *attr)
{
    osThreadAttr_t taskAttr = {attr->name, 0, NULL, 0, NULL, attr->stackSize, attr->priority, 0, 0};
    return (ThreadId)osThreadNew((osThreadFunc_t)run, argv, &taskAttr);
}
