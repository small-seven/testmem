#include "init_jobs.h"
#include <stdio.h>
#include <string.h>
#include "init_cmds.h"
#include "securec.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
#define JOBS_ARR_NAME_IN_JSON "jobs"
#define CMDS_ARR_NAME_IN_JSON "cmds"
#define MAX_JOBS_COUNT        10
void ReleaseAllJobs()
{
    if (g_jobs == NULL) {
        return;
    }

    for (int i = 0; i < g_jobCnt; ++i) {
        if (g_jobs[i].cmdLines != NULL) {
            free(g_jobs[i].cmdLines);
            g_jobs[i].cmdLines = NULL;
            g_jobs[i].cmdLinesCnt = 0;
        }
    }

    free(g_jobs);
    g_jobs = NULL;
    g_jobCnt = 0;
}
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
