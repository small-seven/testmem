#include <fcntl.h>
#define LIBSSH_STATIC
#include <libssh/sftp.h>
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "libavutil/attributes.h"
#include "libavformat/avio.h"
#include "avformat.h"
#include "internal.h"
#include "url.h"
typedef struct {
    const AVClass *class;
    ssh_session session;
    sftp_session sftp;
    sftp_file file;
    sftp_dir dir;
    int64_t filesize;
    int rw_timeout;
    int trunc;
    char *priv_key;
} LIBSSHContext;
#define OFFSET(x) offsetof(LIBSSHContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM
