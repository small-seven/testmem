#include "securec.h"
#include "coap_adapter.h"
#define COAP_MAX_ENDPOINTS_NUM 64
#define COAP_LOW_DELTA_NUM 13
#define COAP_MID_DELTA_NUM 256
#define COAP_EXTEND_DELTA_VALUE_UINT8 13
#define COAP_EXTEND_DELTA_VALUE_UINT16 14
#define COAP_EXTEND_DELTA_VALUE_INVALID 15
#define COAP_OPTION_MAX_LEN 64
#define COAP_OPTION_EXTENSION_LEN   2
#define COAP_SHIFT_BIT8 8
#define COAP_SHIFT_BIT6 6
#define COAP_SHIFT_BIT4 4
#define BUF_OFFSET_BYTE2 2
#define BUF_OFFSET_BYTE3 3
#define BUF_OFFSET_BYTE4 4
#define MSGID_HIGHT_BYTE 2
static int COAP_CreateHeader(COAP_Packet *pkt, const COAP_PacketParam *pktParam, COAP_ReadWriteBuffer *buf)
{
    if (buf->len != 0) {
        return DISCOVERY_ERR_INVALID_ARGUMENT;
    }

    if ((pktParam->protocol != COAP_UDP) && (pktParam->protocol != COAP_TCP)) {
        return DISCOVERY_ERR_TRANSPORT_NOT_UDP_OR_TCP;
    }
    pkt->protocol = pktParam->protocol;

    if (pktParam->type > COAP_TYPE_RESET) {
        return DISCOVERY_ERR_UNKNOWN_MSG_TYPE;
    }

    if (buf->size < HEADER_LEN) {
        return DISCOVERY_ERR_PKT_EXCEED_MAX_PDU;
    }

    pkt->header.type = (unsigned int)pktParam->type & 0x03;
    pkt->header.ver = COAP_VERSION;
    pkt->header.code = pktParam->code;

    if (pkt->protocol == COAP_UDP) {
        pkt->header.varSection.msgId = pktParam->msgId;
        buf->readWriteBuf[0] = (char)(pkt->header.ver << COAP_SHIFT_BIT6);
        buf->readWriteBuf[0] = (char)((unsigned char)buf->readWriteBuf[0] |
            (unsigned char)(pkt->header.type << COAP_SHIFT_BIT4));
        buf->readWriteBuf[1] = (char)pkt->header.code;
        buf->readWriteBuf[BUF_OFFSET_BYTE2] = (char)((pkt->header.varSection.msgId & 0xFF00) >> COAP_SHIFT_BIT8);
        buf->readWriteBuf[BUF_OFFSET_BYTE3] = (char)(pkt->header.varSection.msgId & 0x00FF);
    } else {
        return DISCOVERY_ERR_NOT_SUPPORTED;
    }
    pkt->len = buf->len = HEADER_LEN;
    return DISCOVERY_ERR_SUCCESS;
}
static int COAP_CreateBody(COAP_Packet *pkt, const COAP_PacketParam *param, const COAP_Buffer *token,
    const COAP_Buffer *payload, COAP_ReadWriteBuffer *buf)
{
    int i;
    int ret;

    if (token != NULL) {
        ret = COAP_AddToken(pkt, token, buf);
        if (ret != DISCOVERY_ERR_SUCCESS) {
            return ret;
        }
    }

    if (param->options != 0) {
        if (param->optionsNum > COAP_MAX_OPTION) {
            return DISCOVERY_ERR_SERVER_ERR;
        }

        for (i = 0; i < param->optionsNum; i++) {
            ret = COAP_AddOption(pkt, &param->options[i], buf);
            if (ret != DISCOVERY_ERR_SUCCESS) {
                return ret;
            }
        }
    }

    if (payload != NULL) {
        ret = COAP_AddData(pkt, payload, buf);
        if (ret != DISCOVERY_ERR_SUCCESS) {
            return ret;
        }
    }

    return DISCOVERY_ERR_SUCCESS;
}
#define COAP_MAX_TOKEN_LEN 8
#define COAP_MAX_TOKEN_ELEMENT_VALUE 256
#define RAND_DIVISOR 0
typedef struct {
    COAP_Packet *pkt;
    COAP_PacketParam *param;
    const unsigned char *payload;
    unsigned long payloadLen;
} COAP_ResponseInfo;
#define PKT_TOKEN_LEN 2
#define COAP_MAX_PDU_SIZE 1024
