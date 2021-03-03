#include "lwip/apps/tftp_server.h"
#if LWIP_UDP
#include "lwip/udp.h"
#include "lwip/timeouts.h"
#include "lwip/debug.h"
#define TFTP_MAX_PAYLOAD_SIZE 512
#define TFTP_HEADER_LENGTH    4
#define TFTP_RRQ   1
#define TFTP_WRQ   2
#define TFTP_DATA  3
#define TFTP_ACK   4
#define TFTP_ERROR 5
#include <string.h>
#endif /* LWIP_UDP */
