#include "avformat.h"
#include "mms.h"
#include "internal.h"
#include "avio_internal.h"
#include "libavutil/intreadwrite.h"
#include "libavcodec/bytestream.h"
#include "network.h"
#include "url.h"
#define LOCAL_ADDRESS 0xc0a80081    // FIXME get and use correct local ip address.
#define LOCAL_PORT    1037          // as above.
typedef enum {
    CS_PKT_INITIAL                  = 0x01,
    CS_PKT_PROTOCOL_SELECT          = 0x02,
    CS_PKT_MEDIA_FILE_REQUEST       = 0x05,
    CS_PKT_START_FROM_PKT_ID        = 0x07,
    CS_PKT_STREAM_PAUSE             = 0x09,
    CS_PKT_STREAM_CLOSE             = 0x0d,
    CS_PKT_MEDIA_HEADER_REQUEST     = 0x15,
    CS_PKT_TIMING_DATA_REQUEST      = 0x18,
    CS_PKT_USER_PASSWORD            = 0x1a,
    CS_PKT_KEEPALIVE                = 0x1b,
    CS_PKT_STREAM_ID_REQUEST        = 0x33,
} MMSCSPacketType;
typedef enum {
    /** Control packets. */
    /*@{*/
    SC_PKT_CLIENT_ACCEPTED          = 0x01,
    SC_PKT_PROTOCOL_ACCEPTED        = 0x02,
    SC_PKT_PROTOCOL_FAILED          = 0x03,
    SC_PKT_MEDIA_PKT_FOLLOWS        = 0x05,
    SC_PKT_MEDIA_FILE_DETAILS       = 0x06,
    SC_PKT_HEADER_REQUEST_ACCEPTED  = 0x11,
    SC_PKT_TIMING_TEST_REPLY        = 0x15,
    SC_PKT_PASSWORD_REQUIRED        = 0x1a,
    SC_PKT_KEEPALIVE                = 0x1b,
    SC_PKT_STREAM_STOPPED           = 0x1e,
    SC_PKT_STREAM_CHANGING          = 0x20,
    SC_PKT_STREAM_ID_ACCEPTED       = 0x21,
    /*@}*/
typedef struct MMSTContext {
    MMSContext  mms;
    int outgoing_packet_seq;             ///< Outgoing packet sequence number.
    char path[256];                      ///< Path of the resource being asked for.
    char host[128];                      ///< Host of the resources.
    int incoming_packet_seq;             ///< Incoming packet sequence number.
    int incoming_flags;                  ///< Incoming packet flags.
    int packet_id;                       ///< Identifier for packets in the current stream.
    unsigned int header_packet_id;       ///< default is 2.
} MMSTContext;
