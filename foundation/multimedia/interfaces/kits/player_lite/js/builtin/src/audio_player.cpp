#include "audio_player.h"
#include <errno.h>
#include <sys/prctl.h>
#include <sys/time.h>
#include <unistd.h>
#include "js_async_work.h"
#include "media_log.h"
#define DELETE_NOT_NULL(pointer) \
