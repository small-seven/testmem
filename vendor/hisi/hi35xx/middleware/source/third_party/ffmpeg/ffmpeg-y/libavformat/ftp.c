#include "libavutil/avstring.h"
#include "libavutil/internal.h"
#include "libavutil/parseutils.h"
#include "avformat.h"
#include "internal.h"
#include "url.h"
#include "libavutil/opt.h"
#include "libavutil/bprint.h"
#define CONTROL_BUFFER_SIZE 1024
#define DIR_BUFFER_SIZE 4096
typedef enum {
    UNKNOWN,
    READY,
    DOWNLOADING,
    UPLOADING,
    LISTING_DIR,
    DISCONNECTED
} FTPState;
typedef enum {
    UNKNOWN_METHOD,
    NLST,
    MLSD
} FTPListingMethod;
typedef struct {
    const AVClass *class;
    URLContext *conn_control;                    /**< Control connection */
    URLContext *conn_data;                       /**< Data connection, NULL when not connected */
    uint8_t control_buffer[CONTROL_BUFFER_SIZE]; /**< Control connection buffer */
    uint8_t *control_buf_ptr, *control_buf_end;
    int server_data_port;                        /**< Data connection port opened by server, -1 on error. */
    int server_control_port;                     /**< Control connection port, default is 21 */
    char *hostname;                              /**< Server address. */
    char *user;                                  /**< Server user */
    char *password;                              /**< Server user's password */
    char *path;                                  /**< Path to resource on server. */
    int64_t filesize;                            /**< Size of file on server, -1 on error. */
    int64_t position;                            /**< Current position, calculated. */
    int rw_timeout;                              /**< Network timeout. */
    const char *anonymous_password;              /**< Password to be used for anonymous user. An email should be used. */
    int write_seekable;                          /**< Control seekability, 0 = disable, 1 = enable. */
    FTPState state;                              /**< State of data connection */
    FTPListingMethod listing_method;             /**< Called listing method */
    char *features;                              /**< List of server's features represented as raw response */
    char *dir_buffer;
    size_t dir_buffer_size;
    size_t dir_buffer_offset;
    int utf8;
} FTPContext;
#define OFFSET(x) offsetof(FTPContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM
