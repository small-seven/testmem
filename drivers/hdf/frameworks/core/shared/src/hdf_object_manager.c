#include "hdf_object_manager.h"
void HdfObjectManagerFreeObject(struct HdfObject *object)
{
    const struct HdfObjectCreator *targetCreator = NULL;
    if (object == NULL) {
        return;
    }
    targetCreator = HdfObjectManagerGetCreators(object->objectId);
    if ((targetCreator == NULL) || (targetCreator->Release == NULL)) {
        return;
    }
    targetCreator->Release(object);
}