#include "hcs_generate_tree.h"
#include "hcs_blob_if.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG hcs_generate_tree
static struct DeviceResourceNode *CreateTreeNode(const char *start, int32_t offset,
    struct DeviceResourceNode *parentNode, char **treeMem)
{
    struct DeviceResourceNode *newNode = (struct DeviceResourceNode *)(*treeMem);
    *treeMem += sizeof(struct DeviceResourceNode);
    newNode->name = start + offset + HCS_PREFIX_LENGTH;
    newNode->hashValue = offset + sizeof(struct HbcHeader);
    if (parentNode != NULL) {
        newNode->parent = parentNode;
        struct DeviceResourceNode *curNode = parentNode->child;
        while ((curNode != NULL) && (curNode->sibling != NULL)) {
            curNode = curNode->sibling;
        }
        if (curNode == NULL) {
            parentNode->child = newNode;
        } else {
            curNode->sibling = newNode;
        }
    }
    return newNode;
}
