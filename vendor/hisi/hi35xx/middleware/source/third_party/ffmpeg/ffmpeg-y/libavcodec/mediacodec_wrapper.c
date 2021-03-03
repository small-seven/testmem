#include <jni.h>
#include "libavutil/avassert.h"
#include "libavutil/mem.h"
#include "libavutil/avstring.h"
#include "avcodec.h"
#include "ffjni.h"
#include "version.h"
#include "mediacodec_wrapper.h"
#define JNI_GET_ENV_OR_RETURN(env, log_ctx, ret) do {              \
#define JNI_GET_ENV_OR_RETURN_VOID(env, log_ctx) do {              \
#define CREATE_CODEC_BY_NAME   0
#define CREATE_DECODER_BY_TYPE 1
#define CREATE_ENCODER_BY_TYPE 2
#define DECLARE_FF_AMEDIACODEC_CREATE_FUNC(name, method) \
