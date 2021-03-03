#include "lwip/apps/mqtt.h"
#include "lwip/apps/mqtt_priv.h"
#include "lwip/timeouts.h"
#include "lwip/ip_addr.h"
#include "lwip/mem.h"
#include "lwip/err.h"
#include "lwip/pbuf.h"
#include "lwip/altcp.h"
#include "lwip/altcp_tcp.h"
#include "lwip/altcp_tls.h"
#include <string.h>
#if LWIP_TCP && LWIP_CALLBACK_API
#if !defined MQTT_DEBUG || defined __DOXYGEN__
#define MQTT_DEBUG                  LWIP_DBG_OFF
#endif
#define MQTT_DEBUG_TRACE        (MQTT_DEBUG | LWIP_DBG_TRACE)
#define MQTT_DEBUG_STATE        (MQTT_DEBUG | LWIP_DBG_STATE)
#define MQTT_DEBUG_WARN         (MQTT_DEBUG | LWIP_DBG_LEVEL_WARNING)
#define MQTT_DEBUG_WARN_STATE   (MQTT_DEBUG | LWIP_DBG_LEVEL_WARNING | LWIP_DBG_STATE)
#define MQTT_DEBUG_SERIOUS      (MQTT_DEBUG | LWIP_DBG_LEVEL_SERIOUS)
#define MQTT_CTL_PACKET_TYPE(fixed_hdr_byte0) ((fixed_hdr_byte0 & 0xf0) >> 4)
#define MQTT_CTL_PACKET_QOS(fixed_hdr_byte0) ((fixed_hdr_byte0 & 0x6) >> 1)
#if defined(LWIP_DEBUG)
#endif
#define mqtt_ringbuf_free(rb) (MQTT_OUTPUT_RINGBUF_SIZE - mqtt_ringbuf_len(rb))
#define mqtt_ringbuf_linear_read_length(rb) LWIP_MIN(mqtt_ringbuf_len(rb), (MQTT_OUTPUT_RINGBUF_SIZE - (rb)->get))
mqtt_client_free(mqtt_client_t *client)
{
  mem_free(client);
}
#if LWIP_ALTCP && LWIP_ALTCP_TLS
#endif
#endif /* LWIP_TCP && LWIP_CALLBACK_API */
