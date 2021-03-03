#include "dmslite_msg_parser.h"
#include <stdlib.h>
#include <unistd.h>
#include "distributed_service_interface.h"
#include "dmslite_check_remote_permission.h"
#include "dmslite_famgr.h"
#include "dmslite_inner_common.h"
#include "dmslite_log.h"
#include "dmslite_tlv_common.h"
static void TlvFreeNodeListMem(TLV_NODE_S *node)
{
    TLV_NODE_S *next = NULL;
    while (node != NULL) {
        next = node->next;
        free(node);
        node = next;
    }
}
