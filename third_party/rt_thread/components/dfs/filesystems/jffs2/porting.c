#include <linux/kernel.h>
#include "nodelist.h"
#include "porting.h"
void jffs_mutex_release(LosMux *mutex)
{
    (void)LOS_MuxUnlock(mutex);
}
void jffs_mutex_create(LosMux *mutex)
{
    (void)LOS_MuxInit(mutex, NULL);
}
void jffs_event_create(PEVENT_CB_S event_CB)
{
	(void)LOS_EventInit(event_CB);
}
void jffs_event_detach(PEVENT_CB_S event_CB)
{
	(void)LOS_EventWrite(event_CB, 0xFFFFFFFF);
}
