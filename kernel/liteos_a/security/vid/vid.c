#include "vid_type.h"
#include "vid_api.h"
#include "los_memory.h"
void VidMapDestroy(LosProcessCB *processCB)
{
    TimerIdMapNode *idNode = NULL;
    TimerIdMapNode *idNodeNext = NULL;

    LOS_MuxLock(&processCB->timerIdMap.vidMapLock, LOS_WAIT_FOREVER);
    LOS_DL_LIST_FOR_EACH_ENTRY_SAFE(idNode, idNodeNext, &processCB->timerIdMap.head, TimerIdMapNode, node) {
        LOS_ListDelete(&idNode->node);
        LOS_MemFree(m_aucSysMem0, idNode);
    }

    LOS_MuxUnlock(&processCB->timerIdMap.vidMapLock);
    LOS_MemFree(m_aucSysMem0, processCB->timerIdMap.bitMap);
    LOS_MuxDestroy(&processCB->timerIdMap.vidMapLock);
}
static UINT16 GetFreeVid(VOID)
{
    UINT16 i, j;
    UINT32 num;
    UINT32 *tmp = NULL;
    LosProcessCB *processCB = OsCurrProcessGet();
    TimerIdMap *idMap = &processCB->timerIdMap;
    UINT16 mapMaxNum = idMap->mapCount;

    for (i = 0; i < mapMaxNum; i++) {
        num = idMap->bitMap[i];
        for (j = 0; j < INT_BIT_COUNT; j++) {
            if ((num & (1 << j)) == 0) {
                num |= 1 << j;
                idMap->bitMap[i] = num;
                return (INT_BIT_COUNT * i + j);
            }
        }
    }

    /* expand bit map */
    mapMaxNum++;
    if (mapMaxNum > VID_MAP_MAX_NUM) {
        PRINT_ERR("%s %d, timer vid run out\n", __FUNCTION__, __LINE__);
        return MAX_INVALID_TIMER_VID;
    }

    tmp = (UINT32*)LOS_MemAlloc(m_aucSysMem0, mapMaxNum * sizeof(UINT32));
    if (tmp == NULL) {
        PRINT_ERR("%s %d, alloc memory failed\n", __FUNCTION__, __LINE__);
        return MAX_INVALID_TIMER_VID;
    }

    (void)memcpy_s(tmp, mapMaxNum * sizeof(UINT32), idMap->bitMap, (mapMaxNum - 1) * sizeof(UINT32));
    idMap->bitMap = tmp;
    idMap->mapCount = mapMaxNum;
    idMap->bitMap[i] = 1;
    return (INT_BIT_COUNT * i);
}
static VOID ReleaseVid(UINT16 vid)
{
    UINT16 a, b;
    UINT32 *tmpMap = NULL;
    LosProcessCB *processCB = OsCurrProcessGet();
    TimerIdMap *idMap = &processCB->timerIdMap;
    UINT16 mapMaxNum = idMap->mapCount;

    if (vid >= (VID_MAP_MAX_NUM * INT_BIT_COUNT)) {
        return;
    }

    a = vid >> INT_BIT_SHIFT;
    b = vid & (INT_BIT_COUNT - 1);

    idMap->bitMap[a] &= ~(1 << b);

    /* shrink bit map */
    if (mapMaxNum > 1) {
        if (idMap->bitMap[mapMaxNum - 1] == 0) {
            mapMaxNum--;
            tmpMap = LOS_MemRealloc(m_aucSysMem0, idMap->bitMap, mapMaxNum * sizeof(UINT32));
            if (tmpMap) {
                idMap->bitMap = tmpMap;
                idMap->mapCount = mapMaxNum;
            }
        }
    }
}
void RemoveNodeByVid(UINT16 vid)
{
    TimerIdMapNode *tmp = NULL;
    LosProcessCB *processCB = OsCurrProcessGet();

    tmp = FindListNodeByVid(vid);
    if (tmp == NULL) {
        return;
    }

    LOS_MuxLock(&processCB->timerIdMap.vidMapLock, LOS_WAIT_FOREVER);
    LOS_ListDelete(&tmp->node);
    ReleaseVid(tmp->vid);
    LOS_MuxUnlock(&processCB->timerIdMap.vidMapLock);
    LOS_MemFree(m_aucSysMem0, tmp);

    return;
}
