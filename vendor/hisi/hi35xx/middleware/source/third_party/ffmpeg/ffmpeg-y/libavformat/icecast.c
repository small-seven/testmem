#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "network.h"
typedef struct IcecastContext {
    const AVClass *class;
    URLContext *hd;
    int send_started;
    char *user;
    // Options
    char *content_type;
    char *description;
    char *genre;
    int legacy_icecast;
    char *name;
    char *pass;
    int public;
    char *url;
    char *user_agent;
} IcecastContext;
#define DEFAULT_ICE_USER "source"
#define NOT_EMPTY(s) (s && s[0])
#define OFFSET(x) offsetof(IcecastContext, x)
#define E AV_OPT_FLAG_ENCODING_PARAM
