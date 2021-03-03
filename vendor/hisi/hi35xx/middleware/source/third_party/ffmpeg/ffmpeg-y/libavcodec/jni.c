#include "config.h"
#include <stdlib.h>
#include "libavutil/error.h"
#include "jni.h"
#if CONFIG_JNI
#include <jni.h>
#include <pthread.h>
#include "libavutil/log.h"
#include "ffjni.h"
#else
#endif
