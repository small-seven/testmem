#include "config.h"
#if CONFIG_ZLIB
#include <zlib.h>
#endif /* CONFIG_ZLIB */
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/parseutils.h"
#include "avformat.h"
#include "http.h"
#include "httpauth.h"
#include "internal.h"
#include "network.h"
#include "os_support.h"
#include "url.h"
#define BUFFER_SIZE   MAX_URL_SIZE
#define MAX_REDIRECTS 8
#define HTTP_SINGLE   1
#define HTTP_MUTLI    2
#define MAX_EXPIRY    19
#define WHITESPACES " \n\t\r"
typedef enum {
    LOWER_PROTO,
    READ_HEADERS,
    WRITE_REPLY_HEADERS,
    FINISH
}HandshakeState;
typedef struct HTTPContext {
    const AVClass *class;
    URLContext *hd;
    unsigned char buffer[BUFFER_SIZE], *buf_ptr, *buf_end;
    int line_count;
    int http_code;
    /* Used if "Transfer-Encoding: chunked" otherwise -1. */
    uint64_t chunksize;
    int chunkend;
    uint64_t off, end_off, filesize;
    char *location;
    HTTPAuthState auth_state;
    HTTPAuthState proxy_auth_state;
    char *http_proxy;
    char *headers;
    char *mime_type;
    char *http_version;
    char *user_agent;
    char *referer;
#if FF_API_HTTP_USER_AGENT
    char *user_agent_deprecated;
#endif
    char *content_type;
    /* Set if the server correctly handles Connection: close and will close
     * the connection after feeding us the content. */
    int willclose;
    int seekable;           /**< Control seekability, 0 = disable, 1 = enable, -1 = probe. */
    int chunked_post;
    /* A flag which indicates if the end of chunked encoding has been sent. */
    int end_chunked_post;
    /* A flag which indicates we have finished to read POST reply. */
    int end_header;
    /* A flag which indicates if we use persistent connections. */
    int multiple_requests;
    uint8_t *post_data;
    int post_datalen;
    int is_akamai;
    int is_mediagateway;
    char *cookies;          ///< holds newline (\n) delimited Set-Cookie header field values (without the "Set-Cookie: " field name)
    /* A dictionary containing cookies keyed by cookie name */
    AVDictionary *cookie_dict;
    int icy;
    /* how much data was read since the last ICY metadata packet */
    uint64_t icy_data_read;
    /* after how many bytes of read data a new metadata packet will be found */
    uint64_t icy_metaint;
    char *icy_metadata_headers;
    char *icy_metadata_packet;
    AVDictionary *metadata;
#if CONFIG_ZLIB
    int compressed;
    z_stream inflate_stream;
    uint8_t *inflate_buffer;
#endif /* CONFIG_ZLIB */
    AVDictionary *chained_options;
    /* -1 = try to send if applicable, 0 = always disabled, 1 = always enabled */
    int send_expect_100;
    char *method;
    int reconnect;
    int reconnect_at_eof;
    int reconnect_streamed;
    int reconnect_delay_max;
    int listen;
    char *resource;
    int reply_code;
    int is_multi_client;
    HandshakeState handshake_step;
    int is_connected_server;
} HTTPContext;
#define OFFSET(x) offsetof(HTTPContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM
#define DEFAULT_USER_AGENT "Lavf/" AV_STRINGIFY(LIBAVFORMAT_VERSION)
#if FF_API_HTTP_USER_AGENT
#endif
#if CONFIG_ZLIB
#else
#endif /* CONFIG_ZLIB */
#if FF_API_HTTP_USER_AGENT
#endif
#if CONFIG_ZLIB
#endif
#if CONFIG_ZLIB
#define DECOMPRESS_BUF_SIZE (256 * 1024)
#endif /* CONFIG_ZLIB */
#if CONFIG_ZLIB
#endif /* CONFIG_ZLIB */
#if CONFIG_ZLIB
#endif /* CONFIG_ZLIB */
#define HTTP_CLASS(flavor)                          \
#if CONFIG_HTTP_PROTOCOL
#endif /* CONFIG_HTTP_PROTOCOL */
#if CONFIG_HTTPS_PROTOCOL
#endif /* CONFIG_HTTPS_PROTOCOL */
#if CONFIG_HTTPPROXY_PROTOCOL
#endif /* CONFIG_HTTPPROXY_PROTOCOL */
