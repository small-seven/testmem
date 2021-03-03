#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct ADerivativeContext {
    const AVClass *class;
    AVFrame *prev;
    void (*filter)(void **dst, void **prv, const void **src,
                   int nb_samples, int channels);
} ADerivativeContext;
#define DERIVATIVE(name, type)                                          \
#define INTEGRAL(name, type)                                          \
