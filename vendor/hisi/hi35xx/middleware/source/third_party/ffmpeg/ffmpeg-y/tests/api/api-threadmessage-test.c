#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/frame.h"
#include "libavutil/threadmessage.h"
#include "libavutil/thread.h" // not public
#define MAGIC 0xdeadc0de
#define SPAWN_THREADS(type) do {                                                \
#define WAIT_THREADS(type) do {                                                 \
