#include "hdf_slist.h"
#include "hdf_log.h"
#define HDF_LOG_TAG utils_slist
void HdfSListRemove(struct HdfSList *list, struct HdfSListNode *link)
{
    struct HdfSListNode *iterator = NULL;
    if (list == NULL || link == NULL) {
        return;
    }

    for (iterator = (struct HdfSListNode *)list; iterator; iterator = iterator->next) {
        if (iterator->next == link) {
            iterator->next = link->next;
            return;
        }
    }
}
void HdfSListIteratorRemove(struct HdfSListIterator *iterator)
{
    if ((iterator == NULL) || (iterator->current == NULL) || (iterator->previous == NULL)) {
        return;
    }

    iterator->current = iterator->current->next;
    iterator->previous->next = iterator->current;
    iterator->stepOnNext = 0;
}
