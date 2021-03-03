#include "dmslite_tlv_common.h"
#include <stdbool.h>
#include <string.h>
#include "securec.h"
#include "dmslite_log.h"
#define MAX_VALID_NODES 4
#define HIGH_BIT_MASK 0xFF
#define LOW_BIT_MASK 0x7F
#define TLV_LENGTH_SHIFT_BITS 7
#define BREAK_IF_FAILURE(errCode);       \
static inline TLV_NODE_S* MallocTlvNode()
{
    TLV_NODE_S *node = malloc(sizeof(TLV_NODE_S));
    if (node == NULL) {
        HILOGE("[Out of memory]");
        return NULL;
    }
    /* won't fail */
    (void) memset_s(node, sizeof(TLV_NODE_S), 0x00, sizeof(TLV_NODE_S));

    return node;
}
